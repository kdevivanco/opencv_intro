
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

Mat img_hsv;
Mat mask;
int hmin = 145;
int smin = 0;
int vmin = 0;

int hmax = 179;
int smax = 255;
int vmax = 255;


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
        
            
                //To do that we must find the perimeter
                float peri = arcLength(contours[i],true); //True makes reference to if the contour is closed
                string per = to_string(peri);

                //Now we must find the corner points (number of curves)
                approxPolyDP(contours[i],conPoly[i],0.02*peri,true); //true = closed
                //conPoly = array of values of curves

                //The length of any of conPoly will give us an aproximation of the shape
                cout << conPoly[i].size() << endl;


                //To draw rectangles around the shape: 
                boundRect[i] = boundingRect(conPoly[i]); 

                int objCor = (int)conPoly[i].size(); //(int) converts to integer

                if(objCor >= 6 && peri > 60){ 
                    //objectType = "circle";
                drawContours(img,contours,i,Scalar(255,0,255),1);
                putText(img,per,{boundRect[i].x,boundRect[i].y-5},FONT_HERSHEY_DUPLEX,0.5,Scalar(0,0,100),1);


                //putText(img,objectType,{boundRect[i].x,boundRect[i].y-5},FONT_HERSHEY_DUPLEX,0.5,Scalar(0,0,100),2);
                }

            }
        
    }



//// IMPORTING IMAGES ///// 
vector<Mat> crop_faces(vector<string> paths){
    vector<Mat> faces;
    CascadeClassifier faceCascade;
    CascadeClassifier eyeCascade;

    if(!faceCascade.load("/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/haarcascade_frontalface_default.xml")){
        cout << "Error loading cascade classifier" << endl;
        return faces;
    }

    if (!eyeCascade.load("/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/haarcascade_eye.xml")) {
        cout << "Error loading eye cascade classifier" << endl;
        return faces;
    }

        int targetWidth = 600;  // Desired width of the cropped images

    for (const auto& path : paths){
        Mat img = imread(path);
        
        if (img.empty()){
            cout << "Error loading image: " << path << endl;
            continue;
        }

        //resize(img, img, Size(300, 300));

        vector<Rect> facesRect;

        faceCascade.detectMultiScale(img, facesRect, 1.1, 10);

        for(int i = 0; i < facesRect.size(); i++){
            rectangle(img, facesRect[i].tl(), facesRect[i].br(), Scalar(0, 0, 255), 3);

            Rect roi(facesRect[i].tl().x, facesRect[i].tl().y, facesRect[i].br().x - facesRect[i].tl().x, (facesRect[i].br().y - facesRect[i].tl().y) / 1.5);

            Mat imgCrop = img(roi);

            // Resize cropped image to a fixed width while maintaining aspect ratio
            int newWidth = targetWidth;
            int newHeight = static_cast<int>(static_cast<float>(imgCrop.rows) / imgCrop.cols * newWidth);
            resize(imgCrop, imgCrop, Size(newWidth, newHeight));

            Mat gray;
            cvtColor(imgCrop, gray, COLOR_BGR2GRAY);

            vector<Rect> eyesRect;
            eyeCascade.detectMultiScale(gray, eyesRect);
            //faces.push_back(gray);
            int count = 1;
            
            cout << eyesRect.size() << " rectangles" << endl;
            // if (eyesRect.size() > 2){
            //     eyesRect.pop_back();
            // }
            
            for (const auto& eyeRect : eyesRect) {
                
                
                cout << eyeRect.size() << endl;
                Point eyeRectTl(eyeRect.x-10, eyeRect.y);
                Point eyeRectBr(eyeRect.x + eyeRect.width + 20, eyeRect.y + eyeRect.height);

                // Point roiEyeRectTl(facesRect[i].tl().x + eyeRectTl.x -10, facesRect[i].tl().y + eyeRectTl.y);
                // Point roiEyeRectBr(facesRect[i].tl().x + eyeRectBr.x +10, facesRect[i].tl().y + eyeRectBr.y);
                
                rectangle(imgCrop, eyeRectTl, eyeRectBr, Scalar(0, 255, 0), 2);
                Rect roi(eyeRectTl, eyeRectBr);
                Mat imgCropEye = imgCrop(roi);
                Mat imgGray, imgBlur, imgCanny, img_dilated, imgErode;

                cvtColor(imgCropEye,imgGray,COLOR_BGR2GRAY);
                GaussianBlur(imgGray,imgBlur,Size(3,3),7,2);
                Canny(imgBlur, imgCanny,120,120);
                Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
                dilate(imgCanny,img_dilated,kernel);
                getContours(img_dilated,imgCropEye);
                //faces.push_back(img_dilated);
                //faces.push_back(imgCropEye);


            }

            faces.push_back(imgCrop);
            
        }
    }

    return faces;
}


//No output func?? wasnt allowed
int main(){

    vector<string> paths = {
        "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/faces/f1.png",
        "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/faces/f2.png",
        "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/faces/f3.png ",
        "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/faces/f4.png",
        "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/faces/f5.png",
        "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/faces/f7.png",
        "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/test.png"
        };
    

    vector<Mat> faces = crop_faces(paths);

    // namedWindow("Trackbars",(640,200));
    // //Hue minimum
    // //Adress of the value and maximum value;
    // createTrackbar("Hue min", "Trackbars", &hmin, 179);
    // createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    // createTrackbar("Sat min", "Trackbars", &smin, 255);
    // createTrackbar("Sat min", "Trackbars", &smax, 255);
    // createTrackbar("Val min", "Trackbars", &vmin, 255);
    // createTrackbar("Val min", "Trackbars", &vmin, 255);

    // cvtColor(faces[10], img_hsv, COLOR_BGR2HSV);

    // while(true){


    //     Scalar lower(hmin,smin,vmin);
    //     Scalar upper(hmax,smax,vmax);
    //     // Threshold the HSV image to get only colors we are interested in


    //     //Then transform
    //     inRange(img_hsv,lower,upper,mask);
    //     //mask will be our output image
    //     //So the output will be a range of colors

        
    //     imshow("hsv",img_hsv);
    //     imshow("mask",mask);
    //     waitKey(1000);

    // }
    
    imshow("ImageName", faces[0]);
    imshow("d", faces[1]);
    imshow("da", faces[2]);
    imshow("ds", faces[3]);
    imshow("1",faces[4]);
    imshow("2",faces[5]);
   // imshow("3", faces[6]);
    // imshow("4", faces[7]);
    // imshow("5a", faces[8]);
    // imshow("5s", faces[9]);
    // imshow("6",faces[10]);
    // imshow("7",faces[11]);
    // imshow("8", faces[12]);


    waitKey(20000); //Whenever it opens up it will not close until we pres the open button


    return 0;
    

}