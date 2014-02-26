#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdio.h>   
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace cv;
using namespace std;

int main( )
{
    Mat image,fin_img;
    image = imread("win.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << endl ;
        return -1;
    }

  // namedWindow( "Display window", CV_WINDOW_AUTOSIZE );// Create a window for display.
                      // Show our image inside it.

    // Create Windows
   // namedWindow("Red",1);
    //namedWindow("Green",1);
    //namedWindow("Blue",1);

    // Create Matrices (make sure there is an image in input!)

    Mat channel[3];
    imshow( "Original Image", image );


    // The actual splitting.
    split(image, channel);
	imshow("Red",channel[2]);
	imshow("Green",channel[1]);
	imshow("Blue",channel[0]);


   channel[0]=Mat::zeros(image.rows, image.cols, CV_8UC1);//Set blue channel to 0

    //Merging red and green channels

    merge(channel,3,image);
    imshow("R+G", image);
    imwrite("dest.jpg",image);

    waitKey(0);//Wait for a keystroke in the window
    return 0;
}

