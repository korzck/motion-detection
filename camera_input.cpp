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
    Mat comparing_frame;
    Mat background;
    cap >> comparing_frame;
    int counter = 0;
    while(true)
    {
        cap >> frame;
        imshow("original", frame);
        int c = waitKey(1);
        if(c == int('c'))
        {
            destroyAllWindows();
            return 0;
        }        

        comparing_frame = comparing_frame - frame;
        imshow("filtered", filter(comparing_frame));
        comparing_frame = frame.clone();
    }
}
