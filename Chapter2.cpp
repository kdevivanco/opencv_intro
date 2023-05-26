
//Reference: https://www.youtube.com/watch?v=2FYm3GOonhk

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//Modifying images
int main(){

    string path = "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/test.png";
    Mat img = imread(path);
    Mat imgGray; //Create destination img
    Mat imgBlur, imgCanny, imgDialation, imgErode;
    //Color modification 
    //Parameters: input, output, old to new function 
    cvtColor(img,imgGray,COLOR_BGR2GRAY);

    //Blur
    GaussianBlur(img,imgBlur,Size(3,3),3,0);

    //Edge detector
    //when we use edge detector it is good practice to blur the image beforehand
    //Parameters: input, output, kernel size, sigma, border type
    Canny(imgBlur, imgCanny,25,75);
    //The lower the values, the more edges

    // Canny(img,img,50,150,3);
    // Canny(imgBlur,imgBlur,50,150,3);
    //Canny(imgGray,imgGray,50,150,3);

    //?? Trackbars

    //Dilating edges: 
    //Dilate - Makes lines thicker
    //Parameters of dialate function: 
    //input, output, kernel size, iterations, border type
    //Kernel ++ increases dialtion 
    //Kernel a square shaped shape that is filled with ones
    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
    dilate(imgCanny,imgDialation,kernel);

    //Eroding edges: 
    //Erode function shrinks edges
    //Parameters:
    //input, output, kernel size, iterations, border type
    erode(imgDialation,imgErode,kernel);


    imshow("imgDialation", imgDialation);
    imshow("ImageCanny", imgCanny);
    imshow("imgErosion", imgErode);
    // imshow("OldImage", img);
    // imshow("NewImage", imgGray);
    waitKey(0); 

}

