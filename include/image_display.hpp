#include <iostream>
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat)
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio/videoio.hpp>

using namespace std;
using namespace cv;

class image_display{
public:
	Mat Input, Output;
    int read_image(void);
    int read_cam(void);

private:
    int cam_num = 0;
    int apiID = cv::CAP_ANY;


};

int image_display::read_cam(void){

	cv::VideoCapture Cap;

	Cap.open(cam_num+apiID);

	if(!Cap.isOpened())
	{
		cerr << "Error - Cam not accessible !" << endl;
		return 1;
	}

    for(;;)
    {
    	Cap.read(Input);

    	if(Input.empty())
    	{
    		cerr << "Blank frame" << endl;
    		return -1;
    	}
    	Output = Input;
    	imshow("Display", Output);
    	cv::waitKey(10);
    }
    return 0;
}


int image_display::read_image(void){

	Input = imread("./racoon.jpg",0);
	if(Input.empty())
	{
  		cerr << "Blank frame" << endl;
  		return -1;
   	}
	Output = Input;
	imshow("Display", Output);
	cv::waitKey(0);
	return 0;
}
