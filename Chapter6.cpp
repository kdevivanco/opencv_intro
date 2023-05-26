//01:23

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//// COLOR DETECTION //// 
Mat img_hsv;
Mat mask;
int hmin = 145;
int smin = 0;
int vmin = 0;

int hmax = 179;
int smax = 255;
int vmax = 255;


int main() {
    string path = "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/shapes.png";
    Mat img = imread(path);
    namedWindow("Trackbars",(640,200));
    //Hue minimum
    //Adress of the value and maximum value;
    createTrackbar("Hue min", "Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Sat min", "Trackbars", &smin, 255);
    createTrackbar("Sat min", "Trackbars", &smax, 255);
    createTrackbar("Val min", "Trackbars", &vmin, 255);
    createTrackbar("Val min", "Trackbars", &vmin, 255);

    // BGR -> HSV
    //First step is to turn the image into hsv
    cvtColor(img, img_hsv, COLOR_BGR2HSV);

    while(true){


    Scalar lower(hmin,smin,vmin);
    Scalar upper(hmax,smax,vmax);
    // Threshold the HSV image to get only colors we are interested in


    //Then transform
    inRange(img_hsv,lower,upper,mask);
    //mask will be our output image
    //So the output will be a range of colors

    imshow("original", img);
    imshow("hsv",img_hsv);
    imshow("mask",mask);
    waitKey(1);
    }

    return 0;
}
