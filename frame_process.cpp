#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat filter(Mat image)
{
    // Mat image = imread("image.jpeg");
    Mat kernel1 = (Mat_<double>(3,3) << -1, -1, -1, 0, 0, 0, 1, 1, 1);
    Mat filtered_image; 
    filter2D(image, filtered_image, -1 , kernel1, Point(-1, -1), 0, BORDER_DEFAULT);
    return filtered_image;
    // imshow("Original", image);
    // imshow("Filtered", identity);
    // waitKey();
    // imwrite("identity.jpg", identity);
    // destroyAllWindows();

    // waitKey();
    // destroyAllWindows();
}