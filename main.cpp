#include <opencv2/opencv.hpp>
#include <iostream>
#include "frame_process.h"
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
    VideoCapture cap(2);
    
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
        counter++;
        if (counter == 2)
        {
            cap >> comparing_frame;
            counter = 0;
        }

        imshow("filtered", filter(comparing_frame - frame, frame));
    }
}
