//Face detection 
//Reference: https://www.youtube.com/watch?v=2FYm3GOonhk

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
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
    CascadeClassifier faceCascade;
    faceCascade.load("/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/haarcascade_frontalface_default.xml");
    //Then we check if it is loaded propperly or not... 
    if(faceCascade.empty()){
        cout << "Error loading cascade classifier" << endl;
        return -1;
    }
    //Then we resize the image to fit the cascade classifier
    
    //resize(img, img, Size(200, 200));
    //Next we are going to detect the faces
    //So first we must store the bounding boxes
    //We create a vector of rectangles

    vector<Rect> faces;

    faceCascade.detectMultiScale(img,faces,1.1,10);
    //the parameters of detectMultiscale are..
    //img - the image to detect faces in
    //faces - the vector of rectangles
    //1.1 - Scale Factor
    //10 - Min Neighbors
    //So we iterate through the faces and print the coordinates
    for(int i = 0; i < faces.size(); i++){
        rectangle(img,faces[i].tl(),faces[i].br(), Scalar(0, 0, 255), 3);
        }
    


    imshow("ImageName", img);
    waitKey(1000); //Whenever it opens up it will not close until we pres the open button
    return 0;
    

}