#include <opencv2/opencv.hpp>
#include <iostream>
#include "frame_process.cpp"
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
    // namedWindow("main");
    VideoCapture cap(0);
    
    if (!cap.isOpened())
        cout << "cannot open camera" << endl;
    Mat frame;
    Mat comparing_frame;
    cap >> comparing_frame;
    int counter = 0;
    while(true)
    {
        cap >> frame;
        imshow("original", frame);
        // imshow("filtered", filter(frame));
        int c = waitKey(1);
        if(c == int('c'))
        {
            destroyAllWindows();
            return 0;
        }
        c++;
        if (c%2 == 0)
        {
            c = 0;
            comparing_frame = comparing_frame - frame; //get difference
            imshow("filtered", filter(comparing_frame)); //show amplified difference
            comparing_frame = frame.clone(); //write current frame

        }
    }
}
