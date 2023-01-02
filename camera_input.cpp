#include <opencv2/opencv.hpp>
#include <iostream>
#include "frame_process.cpp"
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
    VideoCapture cap(0);
    
    if (!cap.isOpened())
        cout << "cannot open camera" << endl;
    Mat frame;
    namedWindow("original");
    while(true)
    {
        cap >> frame;
        imshow("original", frame);
        // filter(frame);
        // imshow("filtered", frame);
        
    }
    destroyAllWindows();
}
