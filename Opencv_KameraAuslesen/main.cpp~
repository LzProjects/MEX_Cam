//============================================================================
// Name        : main.cpp
// Author      : LZ
//
// Description :
//               
//       		 
//============================================================================


#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    cout << "trying opencv\n";
    // open the first webcam plugged in the computer
    cv::VideoCapture camera(0);

    if (!camera.isOpened()) {
        std::cerr << "ERROR: Could not open camera" << std::endl;
        return 1;
    }
    //camera.set(CV_CAP_PROP_FRAME_WIDTH, 160);
    //camera.set(CV_CAP_PROP_FRAME_HEIGHT, 120);
    
    cout << "1\n";
    
    // create a window to display the images from the webcam
    cv::namedWindow("Webcam", CV_WINDOW_AUTOSIZE);
    
    cout << "2\n";
    
    // this will contain the image from the webcam
    cv::Mat frame;
    cv::Mat image = cv::imread("image.jpeg");

    cout << "3\n";
        
    // capture the next frame from the webcam
    camera >> frame;

     cout << "4\n";
    
    // display the frame until you press a key
    while (1) {
        // show the image on the window
        camera >> frame;
	cv::Size size(160, 120);
	cv::Mat dst;
	cv::resize(frame, dst, size);
	//frame = dst;
	
        cv::imshow("Webcam", frame);
        // wait (10ms) for a key to be pressed
	int key = cv::waitKey(10);

	if (key == 27){
	  break;
	}
	
	switch(key){
	  case 65361: cout << "links" << endl;
	              break;
	  case 65362: cout << "oben" << endl;
	              break;
	  case 65363: cout << "rechts" << endl;
	              break;
          case 65364: cout << "unten" << endl;
	              break;
        }
    }
	return 0;
}
