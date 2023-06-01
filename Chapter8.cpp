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

    string path = "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/facetest2.png";
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
        cout << faces[i].tl();
            cout << faces[i].br();
        //get the x coordinate of faces[i].tl();
        //get the y coordinate of faces[i].tl();
        //get the x coordinate of faces[i].br();
        //get the y coordinate of faces[i].br();
    
        }
    Point p1, p2; 
    p1 = faces[0].tl();
    p2 = faces[0].br();
    cout << p2;
     //CROPPING IMAGES
    //Important to cut object, to add more processing in that specific region 
    // This region is called region of interest -> ROI
    // To crop images, we can use rectangles
    Rect roi(p1.x,p1.y,p2.x - p1.x,(p2.y - p1.y)/1.5); //Inside here we must define x,y witdh and height
    // //So from point 100,100. We go 300px to the right, then 250 bottom
    Mat imgCrop;
    imgCrop = img(roi);
    
    Mat imgGray, imgBlur, imgCanny, img_dilated, imgErode;

    //Preprocessing
    cvtColor(imgCrop,imgGray,COLOR_BGR2GRAY);
    GaussianBlur(imgGray,imgBlur,Size(3,3),3,0);
    Canny(imgBlur, imgCanny,25,75);
    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
    dilate(imgCanny,img_dilated,kernel);
    //This prevents holes in the outlines
   // getContours(img_dilated,img);
//


    imshow("ImageName", img);
    imshow("roi", imgCrop);
    imshow("cnt",img_dilated);

    waitKey(5000); //Whenever it opens up it will not close until we pres the open button
    return 0;
    

}