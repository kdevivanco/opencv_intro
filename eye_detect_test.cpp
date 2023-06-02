
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

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
            faces.push_back(gray);

            for (const auto& eyeRect : eyesRect) {
                Point eyeRectTl(eyeRect.x, eyeRect.y);
                Point eyeRectBr(eyeRect.x + eyeRect.width, eyeRect.y + eyeRect.height);

                Point roiEyeRectTl(facesRect[i].tl().x + eyeRectTl.x, facesRect[i].tl().y + eyeRectTl.y);
                Point roiEyeRectBr(facesRect[i].tl().x + eyeRectBr.x, facesRect[i].tl().y + eyeRectBr.y);

                rectangle(imgCrop, eyeRectTl, eyeRectBr, Scalar(0, 255, 0), 2);
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
        "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/faces/f3.png",
        "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/faces/f4.png",
        "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/faces/f5.png",
        "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/faces/f7.png"
        };
    

    vector<Mat> faces = crop_faces(paths);
    
    imshow("ImageName", faces[0]);
    imshow("d", faces[1]);
    imshow("da", faces[2]);
    imshow("ds", faces[3]);
    
    

    waitKey(20000); //Whenever it opens up it will not close until we pres the open button


    return 0;
    

}