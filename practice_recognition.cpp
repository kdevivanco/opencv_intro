//Reference: https://www.youtube.com/watch?v=2FYm3GOonhk
//01:38
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//// Shapes & contour detection 


int main() {
    string path = "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/brainscan3.jpg";
    Mat img = imread(path);

    // Increase contrast
    Mat imgContrast;
    cvtColor(img, imgContrast, COLOR_BGR2Lab);
    vector<Mat> labChannels(3);
    split(imgContrast, labChannels);
    equalizeHist(labChannels[0], labChannels[0]);
    merge(labChannels, imgContrast);
    cvtColor(imgContrast, imgContrast, COLOR_Lab2BGR);

    // Preprocessing
    Mat imgGray, imgBlur, imgCanny, imgDilated;
    cvtColor(imgContrast, imgGray, COLOR_BGR2GRAY);

    GaussianBlur(imgGray, imgBlur, Size(5, 5), 5, 0);
    Canny(imgBlur, imgCanny, 50, 100);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(imgCanny, imgDilated, kernel);

    // Contour detection
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(imgDilated, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE);

    // Draw contours on the original image
    Mat imgContours = img.clone();
    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());
    ///cout << img.size() << endl;
    string path2 = "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/brainscan.jpg";

    Mat blackimg = imread(path2);
    resize(blackimg,blackimg,Size(),1.8,1.8);


    for (int i = 0; i < contours.size(); i++) {
        int area = contourArea(contours[i]);
        boundRect[i] = boundingRect(contours[i]);

        if (area > 20000 && area < 25000) {
            cout << "Area: " << area << endl;
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            drawContours(imgContours, contours, i, Scalar(255, 0, 255), 2);
            drawContours(imgContours, conPoly, i, Scalar(0, 0, 255), 2);

            string areaText = "Area: " + to_string(area);
            putText(imgContours, areaText, Point(boundRect[i].x, boundRect[i].y - 10), FONT_HERSHEY_DUPLEX, 0.5, Scalar(0, 0, 100), 2);
        }
        if (area>700){
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            drawContours(blackimg, contours, i, Scalar(255, 255, 255), 2);
            //change the x,y coordinate where contours is drawn on drawContours, to draw at the center... 
            Point center(boundRect[i].x + boundRect[i].width / 2, boundRect[i].y + boundRect[i].height / 2);
            drawContours(blackimg, conPoly, i, Scalar(0, 0, 255), 2);


        }
    }
    




    // imshow("Original", img);
    // imshow("imgCanny", imgBlur);
    // imshow("imgCanny", imgCanny);
    // imshow("imgDil", imgDilated);
    imshow("Blank",blackimg);

    imshow("Original Image", imgContours);
    waitKey(200000);

    return 0;
}