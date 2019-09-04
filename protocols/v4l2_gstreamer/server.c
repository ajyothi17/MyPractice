/**
 * File              : server_poll.c
 */
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <linux/ioctl.h>
#include <linux/types.h>
#include <linux/v4l2-common.h>
#include <linux/v4l2-controls.h>
#include <linux/videodev2.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <netdb.h>
#include <time.h>
#include <signal.h>
#include <poll.h>
#include <time.h>

struct stream {
    void *start;
    int length;
};
int sock_id;
int frame = 0;
size_t sendr;   
struct v4l2_capability caps;
struct v4l2_format format1;
struct v4l2_requestbuffers buf_req;
struct v4l2_buffer buf_info;
struct v4l2_buffer buffer_info;
struct v4l2_event_subscription ev;
struct pollfd	p;
int fd, v, data;
int type;
unsigned int iter;
struct stream *buffer;
struct sockaddr_in server_addr;
struct sockaddr_in client_addr;
socklen_t length;
clock_t start_en, end_en, start_st, end_st;

/* Handler function for termination */
void handler(int signum)
{
    /* ioctl to terminate streaming */
    if(ioctl(fd, VIDIOC_STREAMOFF, &type) < 0) {
        perror("VIDIOC_STREAMOFF");
        exit(1);
    }
    printf("No of frame are :%d\n", frame);
    printf("Terminating\n");
    printf("Time in second:%f\n", ((double)end_st - start_st) / CLOCKS_PER_SEC); 
    close(fd);
    free(buffer);
    close(sock_id);
    exit(1);
}

/*
 * \brief Function definition to initialize and set parameters
 * */
void start_device(void)
{
    memset(&caps, 0, sizeof(caps));
    /* ioctl for querying capabilities of connected device */
    if(ioctl(fd, VIDIOC_QUERYCAP, &caps) < 0) {
        perror("VIDIOC_QUERYCAP");
        exit(1);
    }

    /* Checking for capture capability */
    if(!(caps.capabilities & V4L2_CAP_VIDEO_CAPTURE)) {
        fprintf(stderr, "Device does not support video capture\n");
        exit(1);
    }
    /* Checking for streaming capability */
    if(!(caps.capabilities & V4L2_CAP_STREAMING)) {
        fprintf(stderr, "Device does not support video streaming\n");
        exit(1);
    }
    memset(&format1, 0, sizeof(format1));

    /* Setting up the formats required */
    format1.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    format1.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;
    format1.fmt.pix.width = 320;
    format1.fmt.pix.height = 240;

    p.fd = fd;
    p.events = POLLIN | POLLRDNORM;
    p.revents = 0; 
    /* ioctl for setting the required format */
    if(ioctl(fd, VIDIOC_S_FMT, &format1) < 0) {
        perror("VIDIOC_S_FMT");
        exit(1);
    }
#if 1 
    /* Get the video format */
    if (ioctl(fd, VIDIOC_G_FMT, &format1) < 0) {
	printf("Error in get the format\n");
	perror("ioctl");
	exit (EXIT_FAILURE);
    }
    printf("Type of device:%d\n", format1.type);
    printf("width :%d\n", format1.fmt.pix.width);
    printf("height :%d\n", format1.fmt.pix.height);
    printf("pixel format :%d\n", format1.fmt.pix.pixelformat);
    printf("field :%d\n", format1.fmt.pix.field);
    
#endif
	memset(&buf_req, 0, sizeof(buf_req));
	/* Structure for requesting buffers */
    buf_req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf_req.memory = V4L2_MEMORY_MMAP;
    buf_req.count = 15;


    /* ioctl for requesting buffers */
    if(ioctl(fd, VIDIOC_REQBUFS, &buf_req) < 0) {
        perror("VIDIOC_REQBUFS");
        exit(1);
    }

    memset(&buf_info, 0, sizeof(buf_info));
    /* Allocating memory for user buffer */
    buffer = (struct stream *) calloc(buf_req.count, sizeof(*buffer));

    for(iter = 0; iter < buf_req.count; iter++) {

        /* Structure to store status of buffer */
        buf_info.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf_info.memory = V4L2_MEMORY_MMAP;
        buf_info.index = iter;
        /* ioctl for checking status & location of buffers */
        if(ioctl(fd, VIDIOC_QUERYBUF, &buf_info) < 0) {
            perror("VIDIOC_QUERYBUF");
            exit(1);
        }
        buffer[iter].length = buf_info.length;

        /*Mapping descriptor with buffer */
        buffer[iter].start = mmap(NULL, buf_info.length, \
                PROT_READ | PROT_WRITE, MAP_SHARED, fd, buf_info.m.offset);
        if(buffer[iter].start == MAP_FAILED) {
            perror("mmap");
            exit(1);
        }
    }
}

/*
 * \brief Function definition to capture & send frames through socket
 * */
void start_capture(void)
{
    FILE *fp;
    unsigned long int i=0, j, len, limit = 65000, offset = 0;
    int validate;
    int temp;
    int row;
    int col;
    int data;
    register int iter;

    fp = fopen("server.mp4", "w");
    if(fp == NULL) {
        perror("Opening file");
        exit(1);
    }
    signal(SIGINT, handler);
    printf("wating for recive\n");
    
    validate = recvfrom(sock_id, &temp, sizeof(int), 0, \
            (struct sockaddr *)&server_addr, &length);
    if (validate == -1) {
        perror("recvfrom");
        exit(1);
    }
    printf("wating for receive after validation\n");
    memset(&buffer_info, 0, sizeof(buffer_info));
    start_en = clock();
    for(iter = 0; iter < buf_req.count; iter++) {
        buffer_info.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buffer_info.memory = V4L2_MEMORY_MMAP;
        buffer_info.index = iter;
        /*ioctl for enqueing buffer */
        if(ioctl(fd, VIDIOC_QBUF, &buffer_info) < 0) {
            perror("VIDIOC_QBUF");
            exit(1);
        }
    }
    end_en = clock();
    type = buffer_info.type;
    /* ioctl to start streaming */
    if(ioctl(fd, VIDIOC_STREAMON, &type) < 0) {
        perror("VIDIOC_STREAMON");
        exit(1);
    }
    /* Sending buffer size through socket */
    sendr = sendto(sock_id, &buffer_info.length, sizeof(int), 0, \
            (struct sockaddr *)&server_addr, length);
    printf("Sending buffer size is done\n");
    if(sendr == -1) {
        perror("send(server)");
        exit(1);
    }
    printf("--------------\n");
    while(1) {
	frame++;
    	start_st = clock(); 
	if((v = poll((struct pollfd *) &(p.fd), 1, 1000)) == -1) {
            perror("poll");
    	    printf("poll is failed\n");
	    exit(EXIT_FAILURE);
    	}
	end_st = clock();
	if(p.revents & POLLERR || p.revents & POLLHUP || p.revents & POLLNVAL) {
	    printf("Data is not captured\n");
	    exit(EXIT_FAILURE);
    	} else if(p.revents & POLLIN || p.revents & POLLRDNORM || p.revents & V4L2_EVENT_EOS) {
	    printf("Data is available\n");	
            for(iter = 0; iter < buf_req.count; iter++) {
	        /* ioctl for dequeying filled buffer */
                if(ioctl(fd, VIDIOC_DQBUF, &buffer_info) < 0){
                   perror("VIDIOC_QBUF");
                   exit(1);
                }
                /* Writing frame into a file */
                if((fwrite(buffer[iter].start, buffer_info.length, 1, fp) < 0)) {
                   perror("fwrite");
                   exit(1);
                }
		//printf("size of data is:%d", buffer_info.length);
		len = buffer_info.length;
		printf("len is :%ld\n", len);
		while(len) {
		   if(len > limit) {
		        data = sendto(sock_id, ((char *)(buffer[iter].start) + offset), limit,\
		        	0, (struct sockaddr *)&server_addr, \
				sizeof(server_addr));
		        if (data == -1) {
		           printf("1.Error in sendto \n");
		           perror("sendto");
		        }
			offset += limit; 
			len -= limit;
		   } else {
		        data = sendto(sock_id, ((char *)(buffer[iter].start) + \
				     offset), len, 0, (struct sockaddr *)&server_addr, \
			             sizeof(server_addr));
		        if (data == -1) {
		            printf("2.Error in sendto\n");
		            perror("sendto");
		        }
			offset = 0;
			break;
		   }
	       }
	   }
	}
	
        for(iter = 0; iter < buf_req.count; iter++) {
            buffer_info.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
            buffer_info.memory = V4L2_MEMORY_MMAP;
            buffer_info.index = iter;
    	    if(ioctl(fd, VIDIOC_QBUF, &buffer_info) < 0) {
                perror("VIDIOC_QBUF");
                exit(1);
            }
       }
    end_st = clock();
    }
}

/* 
 * \brief Server program for video surviellance
 * */
int main()
{
    const char *device = "/dev/video0";  /* Camera device node */ 
    int binder;                                                   

    /* Creating structure for UDP socket */     
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(6001);
    server_addr.sin_addr.s_addr = (INADDR_ANY);
    length = sizeof(struct sockaddr_in);

    /* Creating tcp socket */
    sock_id = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    /* Binding the socket with the structure */ 
    binder = bind(sock_id, (struct sockaddr *)&server_addr, length);
    if(binder < 0) {
        perror("binder");
        return 0;
    }
    /* Opening camera device node */
    fd = open(device, O_RDWR);
    if(fd < 0) {
        perror("Opening Device");
        return 0;
    }
    printf("Device opened successfully\n");

    start_device();      /* Function call to initialize device */
    start_capture();      /* Function call to start capture and send */
    printf("Time in second :%f\n", ((double)end_en - start_en) / CLOCKS_PER_SEC); 
    //printf("Time in second :%f\n", ((double)end_st - start_st) / CLOCKS_PER_SEC); 
    
    return 0;
}
