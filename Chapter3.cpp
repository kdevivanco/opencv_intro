//Reference: https://www.youtube.com/watch?v=2FYm3GOonhk
// 00:52 min

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

/////Resizing images//// 

using namespace cv;
using namespace std;

int main()
{
    string path = "/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/Resources/test.png";
    Mat img = imread(path);
    Mat imgResize;
    
    cout << img.size() << endl;
    int size1 = 768 ;
    int size2 = 559;

    resize(img,imgResize,Size(500,800));
    //To scale down without using size (to not mess w dimensions)...
    resize(img,imgResize,Size(),0.5,0.5);

    //CROPPING IMAGES
    //Important to cut object, to add more processing in that specific region 
    // This region is called region of interest -> ROI
    // To crop images, we can use rectangles
    Rect roi(200,100,300,400); //Inside here we must define x,y witdh and height
    //So from point 100,100. We go 300px to the right, then 250 bottom
    Mat imgCrop;
    imgCrop = img(roi);
    
    imshow("imgcrop", imgCrop);
    imshow("imgRize", img);
    imshow("imgRize", imgResize);
    waitKey(0);

}
