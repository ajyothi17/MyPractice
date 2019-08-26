#include <cv.h>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <time.h>
#include <sstream>
#include <iomanip>
#include<opencv2/core/core.hpp>
#include<iostream>

using namespace std;
using namespace cv;

const static int SENSITIVITY_VALUE = 40;
const static int BLUR_SIZE = 10;
bool trackingEnabled;

string intToString(int number){
	std::stringstream ss;
	ss << number;
	return ss.str();
};
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
int main(){
	bool recording = false;
	bool startNewRecording = false;
	bool firstRun = true;
	bool motionDetected = false;
	bool pause = false;
	trackingEnabled = false;
	Mat frame1,frame2;
	Mat grayImage1,grayImage2;
	Mat differenceImage;
	Mat thresholdImage;

cout<<"hello"<<endl;
//cv::VideoCapture cap("uridecodebin uri=rtsp://184.72.239.149/vod/mp4:BigBuckBunny_115k.mov ! videoconvert ! videoscale ! appsink");
VideoCapture cap;
cap.open(0);

//cap.open("rtsp://test:9483338984raS#@172.16.9.79:22");
//cap.open("udpsrc port=5000 caps = \"application/x-rtp, media=(string)video, clock-rate=(int)90000, encoding-name=(string)JPEG, payload=(int)96\" ! rtpjpegdepay ! jpegdec ! decodebin ! videoconvert ! autovideosink");

cout<<"hello"<<endl;
        VideoWriter oVideoWriter;//create videoWriter object, not initialized yet

       double dWidth =cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
        double dHeight =cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Frame Size = " << dWidth << "x" << dHeight << endl;
	Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));
	if(!cap.isOpened()){
		cout<<"ERROR ACQUIRING VIDEO FEED\n";
		getchar();
		return -1;
	}
	while(1){

		cap.read(frame1);
		cv::cvtColor(frame1,grayImage1,COLOR_BGR2GRAY);
		cap.read(frame2);
		cv::cvtColor(frame2,grayImage2,COLOR_BGR2GRAY);
		cv::absdiff(grayImage1,grayImage2,differenceImage);
		cv::threshold(differenceImage,thresholdImage,SENSITIVITY_VALUE,255,THRESH_BINARY);
		cv::blur(thresholdImage,thresholdImage,cv::Size(BLUR_SIZE,BLUR_SIZE));
		cv::threshold(thresholdImage,thresholdImage,SENSITIVITY_VALUE,255,THRESH_BINARY);
		if(trackingEnabled){
			motionDetected = detectMotion(thresholdImage,frame1);
		}else{ 
			recording = false;
			motionDetected = false;
		}
		rectangle(frame1,Point(0,460),Point(200,480),Scalar(255,255,255),-1);
		putText(frame1,getDateTime(),Point(0,480),1,1,Scalar(0,0,0),2);
		if(recording){
			oVideoWriter.write(frame1);
			putText(frame1,"REC",Point(0,60),2,2,Scalar(0,0,255),2);
		}
		if(motionDetected){
			putText(frame1,"MOTION DETECTED",cv::Point(0,420),2,2,cv::Scalar(0,255,0));
			recording = true;
			if(firstRun == true){
				string videoFileName = "/home/test/"+getDateTimeForFile()+".avi";
				cout << "File has been opened for writing: " << videoFileName<<endl;
				oVideoWriter  = VideoWriter(videoFileName, CV_FOURCC('D', 'I', 'V', '3'), 20, frameSize, true);
				if (!oVideoWriter.isOpened() ) 
				{
					cout << "ERROR: Failed to initialize video writing" << endl;
					getchar();
					return -1;
				}
				firstRun = false;
			}
		}else recording = false;
		
		if(frame1.empty())
			break;

		imshow("Frame1",frame1);
		switch(waitKey(30)){
		case 27: //'esc' key has been pressed, exit program.
			return 0;
		case 114: //'r' has been pressed. this will toggle tracking
			trackingEnabled = !trackingEnabled;
			cout<<"tracking"<<endl;
			if(trackingEnabled == false)
				cout<<"Tracking disabled."<<endl;
			else 
				cout<<"Tracking enabled."<<endl;
			break;
		}
	
	}
	return 0;

}
