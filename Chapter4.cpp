//Reference: https://www.youtube.com/watch?v=2FYm3GOonhk
// 00:59  min

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

///// Drawing shapes and text on Images//// 

using namespace cv;
using namespace std;

int main()
{
    //Creating images
    Mat img(512,512,CV_8UC3, Scalar(255, 0 ,0)); 
    //CV_8UC3 is the image type range of (0->255) if unsigned
    //3 is the colors (RGB)

    //Black image:
    Mat img2 = Mat::zeros(500, 500, CV_8UC3);

    circle(img,Point(256,256),100,Scalar(0,0,255),10);
    //parameters of circle:
    //Point(x,y) is the center of the circle
    //100 is the radius
    //Scalar(0,0,255) is the color of the circle
    //10 is line thickness
    //If you want it filled, change 10 for filled

    rectangle(img,Point(100,100),Point(200,200),Scalar(255,255,255));
    //parameters of rectangle:
    //Rect(Point(x,y),Point(x,y)) is the rectangle
    //Point(x,y) is the top left corner of the rectangle
    //Point(x,y) is the bottom right corner of the rectangle
    
    line(img,Point(10,10),Point(200,10),Scalar(0,0,23),10);
    //parameters of line:
    //to make a straight line both Y values must match

    putText(img,"HolaMundo",Point(0,130),FONT_HERSHEY_DUPLEX,0.5,Scalar(0,0,100),2);


    imshow("imgRize", img);
    imshow("blackimg",img2);
    waitKey(0);

}
