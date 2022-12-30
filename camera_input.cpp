#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
    namedWindow("main");
    VideoCapture cap(0);
    if (!cap.isOpened())
        cout << "cannot open camera" << endl;
    Mat frame;
    while(true)
    {
        cap >> frame;
        imshow("main", frame);
    }
}
