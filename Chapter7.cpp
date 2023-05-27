//Reference: https://www.youtube.com/watch?v=2FYm3GOonhk
//01:38
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//// Shapes & contour detection 

//New function to find contours
//first parameter: dilated image 
//Second parameter: image we want to draw on
void getContours(Mat dil_img, Mat img){
    // Detect contours
    vector<vector<Point>> contours;
    //Hierarchy
    //Vector of ints
    vector<Vec4i> hierarchy;
    //Vec of four ints

    findContours(dil_img,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    //drawContours(img,contours,-1,Scalar(255,0,255),2);
    //-1 is the contour number (in this case all)

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size()); // Variable
    string objectType;

    //The way we filter using contours, is taking in the size
    for(int i=0; i<contours.size();i++){
        int area = contourArea(contours[i]);
        if(area > 500){
            cout << "Area: " << area << endl;
            if(area>1000){
                //Draw contours
                // drawContours(img,contours,i,Scalar(255,0,255),2);
                //i is the contours that are kept 
                //Now that the obj are filtered,
                //We are going to find the bounding box
                //To do that we must find the perimeter
                float peri = arcLength(contours[i],true); //True makes reference to if the contour is closed
                //Now we must find the corner points (number of curves)
                approxPolyDP(contours[i],conPoly[i],0.02*peri,true); //true = closed
                //conPoly = array of values of curves
                drawContours(img,contours,i,Scalar(255,0,255),2);
                drawContours(img,conPoly,i,Scalar(0,0,255),2);

                //The length of any of conPoly will give us an aproximation of the shape
                cout << conPoly[i].size() << endl;
                //So for example, if the answer is 3, triangle
            
                //To draw rectangles around the shape: 
                boundRect[i] = boundingRect(conPoly[i]); //function 
                //rectangle(img,boundRect[i].tl(),boundRect[i].br(),Scalar(0,255,0),5);

                //Now we want to distinct which shape is which
                int objCor = (int)conPoly[i].size(); //(int) converts to integer
                if(objCor == 3){ objectType = "triangle";}
                else if(objCor == 4){ 
                    //recognize if its square
                    //Dividing height/width, should give 1 (between 0.9 to 1.1)
                    float aspRatio  = (float)boundRect[i].width/(float)boundRect[i].height;
                    if (aspRatio > 0.95 && aspRatio <1.05){
                        objectType = "square";
                        
                    }
                    else{
                    objectType = "rectangle";
                    }
                    cout << aspRatio <<endl;
                    }
                else if(objCor == 8){ objectType = "circle";}

                putText(img,objectType,{boundRect[i].x,boundRect[i].y-5},FONT_HERSHEY_DUPLEX,0.5,Scalar(0,0,100),2);
            }
        }
    }

}

int main(){

    string path = "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/shapes.png";
    Mat img = imread(path);
    //If we can find the edges of our image, then we can find contour points
    Mat imgGray, imgBlur, imgCanny, img_dilated, imgErode;

    //Preprocessing
    cvtColor(img,imgGray,COLOR_BGR2GRAY);
    GaussianBlur(imgGray,imgBlur,Size(3,3),3,0);
    Canny(imgBlur, imgCanny,25,75);
    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
    dilate(imgCanny,img_dilated,kernel);
    //This prevents holes in the outlines
    getContours(img_dilated,img);

    imshow("ImageName", img);
    imshow("ImageGray", imgGray);
    imshow("ImageBlur", imgBlur);
    imshow("ImageCanny", imgCanny);
    imshow("ImageDilated", img_dilated);
    waitKey(10000); 
    return 0;
    

}

//Some notes... 
 //The contours are a vector of vectors of points... 
    //Each vector is a contour
    //Each point is a 2D coordinate
    //So contours[i] = vector of points
    //So contours[i][j] = 2D coordinate
    //So contours[i][j][0] = x

//Concept about filtering out 
 //Now we want to find the area and filter out 
    //the contours that are too small
    //We will iterate through the contours
    //and if the contour size is > 1000
    //we will add it to the contours