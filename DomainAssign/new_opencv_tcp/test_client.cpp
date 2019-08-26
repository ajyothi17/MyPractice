#include "opencv2/opencv.hpp"
#include <cv.h>
#include<opencv2/core/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui.hpp>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace cv;
using namespace std;

const static int SENSITIVITY_VALUE = 40;
const static int BLUR_SIZE = 10;
bool trackingEnabled;

string intToString(int number){
    std::stringstream ss;
    ss << number;
    return ss.str();
}

string getDateTime(){
    struct tm *theTime;
    time_t tim;
    time(&tim);
    theTime = localtime(&tim);
    string dateTime;
    string year = intToString(theTime->tm_year);
    std::stringstream m;
    m<<std::setfill('0')<<std::setw(2)<< theTime->tm_mon;
    string month = m.str();
    std::stringstream d;
    d<<std::setfill('0')<<std::setw(2)<< theTime->tm_mday;
    string day = d.str();
    std::stringstream hr;
    hr<<setfill('0')<<std::setw(2)<<theTime->tm_hour;
    string hour = hr.str();
    std::stringstream min;
    min<<setfill('0')<<std::setw(2)<<theTime->tm_min;
    string minute = min.str();
    std::stringstream sec;
    sec<<setfill('0')<<std::setw(2)<<theTime->tm_sec;
    string second = sec.str();
    dateTime = year + "-" + month + "-" + day + "  " + hour + ":" + minute + ":" + second;
    return dateTime;
};

string getDateTimeForFile(){
    struct tm *theTime;
    time_t tim;
    time(&tim);
    theTime=localtime(&tim);
    string dateTime;
    string year = intToString(theTime->tm_year);
    std::stringstream m;
    m<<std::setfill('0')<<std::setw(2)<< theTime->tm_mon;
    string month = m.str();
    std::stringstream d;
    d<<std::setfill('0')<<std::setw(2)<< theTime->tm_mday;
    string day = d.str();
    std::stringstream hr;
    hr<<setfill('0')<<std::setw(2)<<theTime->tm_hour;
    string hour = hr.str();
    std::stringstream min;
    min<<setfill('0')<<std::setw(2)<<theTime->tm_min;
    string minute = min.str();
    std::stringstream sec;
    sec<<setfill('0')<<std::setw(2)<<theTime->tm_sec;
    string second = sec.str();
    dateTime = year + "_" + month + "_" + day + "_" + hour + "h" + minute + "m" + second + "s";
    return dateTime;
}

bool detectMotion(Mat thresholdImage, Mat &cameraFeed){
    bool motionDetected = false;
    Mat temp;
    thresholdImage.copyTo(temp);
    vector<vector<Point> >contours;
    vector<Vec4i> hierarchy;
    findContours(temp,contours,hierarchy,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE );// retrieves external contours
    if(contours.size()>0)
        motionDetected=true;
    else
        motionDetected = false;
    return motionDetected;
}

int main(int argc, char** argv)
{

    //--------------------------------------------------------
    //networking stuff: socket , connect
    //--------------------------------------------------------
    int         sokt;
    char*       serverIP;
    int         serverPort;

    if (argc < 3) {
           std::cerr << "Usage: cv_video_cli <serverIP> <serverPort> " << std::endl;
		   return -1;
    }

    serverIP   = argv[1];
    serverPort = atoi(argv[2]);

    struct  sockaddr_in serverAddr;
    socklen_t addrLen = sizeof(struct sockaddr_in);

    if ((sokt = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "socket() failed" << std::endl;
		   return -1;
    }

    serverAddr.sin_family = PF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(serverIP);
    serverAddr.sin_port = htons(serverPort);

    if (connect(sokt, (sockaddr*)&serverAddr, addrLen) < 0) {
        std::cerr << "connect() failed!" << std::endl;
		   return -1;
    }



    //----------------------------------------------------------
    //OpenCV Code
    //----------------------------------------------------------

    Mat img1;
    Mat img2;
    img1 = Mat::zeros(480 , 640, CV_8UC1);   
    img2 = Mat::zeros(480 , 640, CV_8UC1);   
    int imgSize1 = img1.total() * img1.elemSize();
    int imgSize2 = img2.total() * img2.elemSize();
    uchar *iptr1 = img1.data;
    uchar *iptr2 = img2.data;
    int bytes = 0;
    int key;
	Mat differenceImage;
	Mat thresholdImage;
	
	bool recording = false;
    bool startNewRecording = false;
    bool firstRun = true;
    bool motionDetected = false;
    bool pause = false;
	VideoWriter oVideoWriter;

    trackingEnabled = true;

    //make img1 continuos
    if ( ! img1.isContinuous() ) {
          img1 = img1.clone();
    }
        
    //make img2 continuos
    if ( ! img2.isContinuous() ) {
          img2 = img2.clone();
    }
    std::cout << "Image Size:" << imgSize1 << std::endl;
    std::cout << "Image Size:" << imgSize2 << std::endl;

	double dWidth = 640; //get the width of frames of the video
    double dHeight = 480; //get the height of frames of the video

   // cout << "Frame Size = " << dWidth << "x" << dHeight << endl;
    Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));


    while (key != 'q') {

        if ((bytes = recv(sokt, iptr1, imgSize1 , MSG_WAITALL)) == -1) {
            std::cerr << "recv failed, received bytes = " << bytes << std::endl;
        }

        if ((bytes = recv(sokt, iptr2, imgSize2 , MSG_WAITALL)) == -1) {
            std::cerr << "recv failed, received bytes = " << bytes << std::endl;
        }
		
		cv::absdiff(img1,img2,differenceImage);
        cv::threshold(differenceImage,thresholdImage,SENSITIVITY_VALUE,255,THRESH_BINARY);		        
		cv::blur(thresholdImage,thresholdImage,cv::Size(BLUR_SIZE,BLUR_SIZE));
        cv::threshold(thresholdImage,thresholdImage,SENSITIVITY_VALUE,255,THRESH_BINARY);
		
		if(trackingEnabled){
            motionDetected = detectMotion(thresholdImage,img1);
        }else{
            recording = false;
            motionDetected = false;
        }
        rectangle(img1,Point(0,460),Point(200,480),Scalar(255,255,255),-1);
        putText(img1,getDateTime(),Point(0,480),1,1,Scalar(0,0,0),2);
        if(recording){
            oVideoWriter.write(img1);
            putText(img1,"REC",Point(0,60),2,2,Scalar(0,0,255),2);
        }
        if(motionDetected){
            putText(img1,"MOTION DETECTED",cv::Point(0,420),2,2,cv::Scalar(0,255,0));
            recording = true;
            if(firstRun == true){
                string videoFileName = "/home/test/"+getDateTimeForFile()+".avi";
                cout << "File has been opened for writing: " << videoFileName<<endl;
                //oVideoWriter  = VideoWriter(videoFileName, CV_FOURCC('D', 'I', 'V', '3'), 20, frameSize, true);
                oVideoWriter  = VideoWriter(videoFileName, VideoWriter::fourcc('D', 'I', 'V', '3'), 20, frameSize, true);
                if (!oVideoWriter.isOpened() )
                {
                    cout << "ERROR: Failed to initialize video writing" << endl;
                    getchar();
                    return -1;
                }
                firstRun = false;
            }
        }else recording = false;

        if(img1.empty())
            break;

    	namedWindow("CV Video Client",CV_WINDOW_AUTOSIZE);
        cv::imshow("CV Video Client", img1);
      
        if (key = cv::waitKey(10) >= 0) break;
    }  

    close(sokt);

    return 0;
}
