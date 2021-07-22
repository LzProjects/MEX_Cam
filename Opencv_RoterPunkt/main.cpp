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
  cout << "Index der Kamera?" << endl;
  int x;
  cin >> x;
    
    // open the first webcam plugged in the computer
    cv::VideoCapture camera(x);
    if (!camera.isOpened()) {
        std::cerr << "ERROR: Could not open camera" << std::endl;
        return 1;
    }

     cout << "Genauigkeit?(x*x Pixel werden jeweils zusammengefasst!)" << endl;
     int genau;
     cin >> genau;
    
    int resX = 640;
    int resY = 480;
    int resizeF = genau;
    int curX = 0;
    int curY = 0;
    
    //camera.set(CV_CAP_PROP_FRAME_WIDTH, resX);
    //camera.set(CV_CAP_PROP_FRAME_HEIGHT, resY);
    
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
	cv::Size size((int)(resX/resizeF), (int)(resY/resizeF));
	cv::Mat dst;
	cv::resize(frame, dst, size);


	cv::rectangle(frame, cv::Point(curX*resizeF, curY*resizeF), cv::Point(curX*resizeF+resizeF, curY*resizeF+resizeF), (0,255,255), 1);

	uchar b = dst.data[dst.channels()*(dst.cols*curY+curX) + 0];
	uchar g = dst.data[dst.channels()*(dst.cols*curY+curX) + 1];
	uchar r = dst.data[dst.channels()*(dst.cols*curY+curX) + 2];
	string farbwerte = "R: " + std::to_string(r) + ", G: " + std::to_string(g) +  ", B: " + std::to_string(b);

	cv::putText(frame, farbwerte, cv::Point(370,30), cv::FONT_HERSHEY_DUPLEX,0.7,CV_RGB(0,0,255),2);
	cv::putText(frame, farbwerte, cv::Point(370,30), cv::FONT_HERSHEY_DUPLEX,0.7,CV_RGB(0,255,0),1);


	for(int lX = 0; lX<resX/resizeF; ++lX){
	  for(int lY = 0; lY<resX/resizeF; ++lY){
	    uchar lB = dst.data[dst.channels()*(dst.cols*lY+lX) + 0];
	    uchar lG = dst.data[dst.channels()*(dst.cols*lY+lX) + 1];
	    uchar lR = dst.data[dst.channels()*(dst.cols*lY+lX) + 2];
	    if(lR-90+abs(lR-150)*0.5>lB && lR-90+abs(lR-150)*0.5>lG && lR>60){
	      cv::rectangle(frame, cv::Point(lX*resizeF, lY*resizeF), cv::Point(lX*resizeF+resizeF, lY*resizeF+resizeF), CV_RGB(255,255,255), 1);
	    }
	  }
	}
	
	
        cv::imshow("Webcam", frame);
        // wait (10ms) for a key to be pressed
	int key = cv::waitKey(10);

	if (key == 27){
	  break;
	}
	
	switch(key){
	  case 65361:
	    cout << "links" << endl;
	    curX = max(0, curX-1);
	    break;
	  case 65362:
	    cout << "oben" << endl;
	    curY =  max(0, curY-1);
	    break;
	  case 65363:
	    cout << "rechts" << endl;
	    curX = min(resX/resizeF, curX+1);
	    break;
          case 65364:
	    cout << "unten" << endl;
	    curY = min(resY/resizeF, curY+1);
	    break;
        }
    }
	return 0;
}
