#include <opencv2/opencv.hpp>
#include <stdio.h>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	Mat image, dst;
	image = imread("image.jpeg", 1);
    Mat kernel;
    Point anchor;
    double delta;
    int ddepth;
    int kernel_size;
    anchor = Point( -1, -1 );
    delta = 0;
    ddepth = -1;
    // Loop - Will filter the image with different kernel sizes each 0.5 seconds
    int ind = 0;
    for(;;)
    {
        // Update kernel size for a normalized box filter
        kernel_size = 3 + 2*( ind%2 );
        kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);
        // Apply filter
        filter2D(image, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );
        imshow("main", dst );
        char c = (char)waitKey(500);
        // Press 'ESC' to exit the program
        if( c == 27 )
        { break; }
        ind++;
    }
	return 0;
}