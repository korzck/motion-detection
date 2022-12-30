#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
    VideoCapture cap = VideoCapture(0);
    Mat frame;
    for (int i = 0; ; i++)
    {
        if(!cap.read(frame))
            cout << "Streaming ended" << endl;
        imshow("main", frame);
    }
}
