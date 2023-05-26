//Reference: https://www.youtube.com/watch?v=2FYm3GOonhk

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//// IMPORTING IMAGES ///// 

//No output func?? wasnt allowed
int main(){

    string path = "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/test.png";
    //Mat is the var type for images 
    //Mat is a ma^trix data type that opencv handles
    //It handles all images
    Mat img = imread(path);

    imshow("ImageName", img);
    waitKey(0); //Whenever it opens up it will not close until we pres the open button

    

}