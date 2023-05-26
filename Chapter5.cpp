//Reference: https://www.youtube.com/watch?v=2FYm3GOonhk
//01:11 hour
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/// WARPING IMAGES

float w = 250; 
float h = 350;
int main(){
    // LOAD IMAGES
    string path = "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/cards.jpg";
    Mat img = imread(path);
    //First we must obtain the coordinates of the pixel where the card starts

    //This function requires floating points
    Point2f src[4] = {{529,142},{771,190},{405,395},{674,457}};
    //Then we must have destination points
    //These are basically a rectangular image
    Point2f dst[4] = {{0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h}};

    //We can warp the image
    Mat img_warped;
    

    //define M
    Mat M = getPerspectiveTransform(src,dst);
    //matrix = getPerspectiveTransform(src,dst); 
    warpPerspective(img, img_warped, M, Size(w,h));
    //Point(w,h) is the size of the final image

    //To write circles around the points selected
    for (int i = 0; i < 4; i++){
        circle(img, src[i], 10, Scalar(0,0,255), 10);

    }

    //This must be done last to not be included in the warp cut

    //We can display the img_warped image
    imshow("img_Warped Image",img_warped);
    imshow("original", img);
    //To show the image only 10 seconds then close cmake
    waitKey(10000);
    //stop running the build....
    return 0;

}
