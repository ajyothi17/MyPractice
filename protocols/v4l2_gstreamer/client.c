/**
 * File              : client1.c
 */
#include <stdio.h>
#include <unistd.h>
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
#include <signal.h>
#include <pthread.h>
#include <poll.h>

struct sockaddr_in server_addr;
struct v4l2_capability caps;
struct v4l2_format format1;
struct v4l2_requestbuffers buf_req;
struct v4l2_buffer buf_info;
struct pollfd	p;
struct v4l2_buffer buffer_info;
struct v4l2_event_subscription ev;
int fd;
void* buff;
FILE *fp;
size_t recvd, sendr;
int sock_id;
int client_id;
socklen_t length;
int val;

void* feed_thread(void *ptr)
{
    while(!val) {
	printf("FEED\n");
        memset(buff, 0, buf_info.length);
        write(fd, buff, buf_info.length);
    }
}

/* Handler for terminating streaming */
void handler(int signum)
{
    close(fd);
    free(fp);
    munmap(buff, buf_info.length);   
    close(client_id);
    exit(1);
}

/*
 * \brief Function definition to initialize and set parameters
 * */
void start_device(void)
{
    int temp = 7;
    memset(&caps, 0, sizeof(caps));
    /* ioctl for querying capabilities of connected device  */
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
    format1.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
    format1.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;
    format1.fmt.pix.width = 320;
    format1.fmt.pix.height = 240;

    p.fd = fd;                                                                  
    p.events = POLLOUT | POLLWRNORM;                                             
    p.revents = 0; 

    /* ioctl for setting the required format */
    if(ioctl(fd, VIDIOC_S_FMT, &format1) < 0) {
        perror("VIDIOC_S_FMT");
        exit(1);
    }

    memset(&buf_req, 0, sizeof(buf_req));
    /* Structure for requesting buffers */
    buf_req.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
    buf_req.memory = V4L2_MEMORY_MMAP;
    buf_req.count = 15;

    /* ioctl for requesting buffers */
    if(ioctl(fd, VIDIOC_REQBUFS, &buf_req) < 0) {
        perror("VIDIOC_REQBUFS");
        exit(1);
    }

    memset(&buf_info, 0, sizeof(buf_info));
    /* Structure to store status of buffer */
    buf_info.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
    buf_info.memory = V4L2_MEMORY_MMAP;
    buf_info.index = 0;

    /* ioctl for checking status & location of buffers  */
    if(ioctl(fd, VIDIOC_QUERYBUF, &buf_info) < 0) {
        perror("VIDIOC_QUERYBUF");
        exit(1);
    }
    /* Sending dummy data for connecting to server */
    sendr = sendto(sock_id, &temp, sizeof(int), 0, \
            (struct sockaddr *)&server_addr, length);
    if(sendr == -1) {
        perror("sendto(client_side)");
        exit(1);
    }

    recvd = recvfrom(sock_id, &buf_info.length, sizeof(int), \
            0, (struct sockaddr *)&server_addr, &length);
    if(recvd == -1) {
        perror("reciever(my_client)");
        exit(1);
    }
    /* Mapping descriptor with buffer */
    buff = mmap(NULL, buf_info.length, PROT_READ | PROT_WRITE, \
            MAP_SHARED, fd, buf_info.m.offset);
    if(buff == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    printf("Initalization of device is done\n");
}

/*
 * \brief Function definition to recieve & write image
 * */
void start_streaming(void)
{
    pthread_t tid;
    int status;
    /*Open a file for client */
    fp = fopen("client.mp4", "w");
    if(fp == NULL) {                                                            
       perror("Opening file");                                                 
       exit(1);                                                                
    }   
    signal(SIGINT,handler);
    status = pthread_create(&tid, NULL, feed_thread, NULL);
    if(status != 0)
        printf("Thread creation failed %s\n", strerror(status));

    /* Looping through buffers */
    while(1) {
        memset(buff, 0, buf_info.length);
        /* Recieving frames */
        recvd = recvfrom(sock_id, buff, buf_info.length, 0, \
                (struct sockaddr *)&server_addr, &length);
	printf("NO of bytes received is :%ld\n", recvd);
        if(recvd == -1) {
            perror("recv(client)");
            exit(1);
        }
        /* Writing frame into a file */                                 
	if((fwrite(buff, recvd, 1, fp) < 0)) {
            perror("fwrite");                                            
            exit(1);                                                     
        }
        val = 1;
        /* Writing into virtual node */
        write(fd, buff, buf_info.length);
        printf("***********MOTION DETECTED***************\n");
    }
}

/*
 * \brief Client program for detecting motion
 * */
int main(int argc, char *argv[])
{
    const char *device = "/dev/video2"; 

    if(argc < 2) {
        printf("ERROR! Invalid input format.Input format: %s <server_ip>\n", argv[0]);
        return 0;
    }
    /* Opening virtual node */
    fd = open(device, O_RDWR);
    if(fd < 0) {
        perror("Opening Device");
        exit(1);
    }

    /* Creating structure for UDP socket */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(6001);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    length = sizeof(struct sockaddr_in);
    /* Creating socket */
    sock_id = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    start_device();        /* Function call to initialize device */ 
    start_streaming();      /* Function call to start streaming */
    return 0;
}
