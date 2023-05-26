
//webcam test

//Reference: https://www.youtube.com/watch?v=2FYm3GOonhk
//Min 30

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//Import webcam

int main(){
    //cap is the name of the video
    VideoCapture cap(0); // If only one camara attached, else camera id 
    //Then we will read the images one by one
    Mat img;

    while(true){
        cap.read(img);
        imshow("Image",img);
        
    waitKey(1);
    }
}