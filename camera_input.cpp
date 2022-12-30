#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
    VideoCapture cap = VideoCapture(0);
    OutputArray frame = {0};
    for (int i = 0; ; i++)
    {
        if(!cap.read())
            cout << "Streaming ended" << endl;

    }
}
