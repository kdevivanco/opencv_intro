//Video test

//Reference: https://www.youtube.com/watch?v=2FYm3GOonhk
//Min 30

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//// Importing Video ////


//We must use a while loop to catch every frame 

int main(){
    //cap is the name of the video
    VideoCapture cap("/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/test_video.mp4");
    //Then we will read the images one by one
    Mat img;

    while(true){
        cap.read(img);
        imshow("Image",img);
    }
    
}
