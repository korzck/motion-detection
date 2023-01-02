#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image = imread("image.jpeg");


    Mat kernel1 = (Mat_<double>(3,3) << -1, -1, -1, 0, 0, 0, 1, 1, 1);
    Mat identity; 
    filter2D(image, identity, -1 , kernel1, Point(-1, -1), 0, BORDER_DEFAULT);
    imshow("Original", image);
    imshow("Filtered", identity);
    waitKey();
    imwrite("identity.jpg", identity);
    destroyAllWindows();

    waitKey();
    destroyAllWindows();
}