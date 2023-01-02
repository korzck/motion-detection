#include <opencv2/opencv.hpp>
#include <iostream>
#include "frame_process.cpp"
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
        int c = waitKey(1);
        if(c == int('c'))
        {
            destroyAllWindows();
            return 0;
        }
    }
}
