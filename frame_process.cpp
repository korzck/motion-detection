#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image = imread("image.jpeg");


    Mat kernel1 = (Mat_<double>(3,3) << 0, 0, 0, 0, 1, 0, 0, 0, 0);
    Mat identity; 
    filter2D(image, identity, -1 , kernel1, Point(-1, -1), 0, 4);
    imshow("Original", image);
    imshow("Identity", identity);
    waitKey();
    imwrite("identity.jpg", identity);
    destroyAllWindows();

    Mat kernel2 = Mat::ones(5,5, CV_64F);

    kernel2 = kernel2 / 25;
    Mat img;
    filter2D(image, img, -1 , kernel2, Point(-1, -1), 0, 4);
    imshow("Original", image);
    imshow("Kernel blur", img);
    imwrite("blur_kernel.jpg", img);
    waitKey();
    destroyAllWindows();
}