#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat filter(Mat image)
{
    // Mat image = imread("image.jpeg");
    Mat kernel1 = (Mat_<double>(3,3) << -1, -1, -1,
                                        -1, 50, -1,
                                        -1, -1, -1);
    Mat laplassian_of_gaussian = (Mat_<double>(5,5) <<   0,   0,  -1,   0,  0,
                                                         0,  -1,  -2,  -1,  0,
                                                        -1,  -2, 16,  -2, -1,
                                                         0,  -1,  -2,  -1,  0,
                                                         0,   0,  -1,   0,  0);
    Mat blacking = (Mat_<double>(3,3) << -1, -1, -1,
                                         1, 1, 1, 
                                         1, 1, 1);
    Mat ident = (Mat_<double>(3,3) <<    0, 0, 0,
                                        0, 0.01, 0, 
                                        0, 0, 0);
    
    Mat filtered_image; 
    filter2D(image, filtered_image, -1 , ident, Point(-1, -1), 0, BORDER_DEFAULT);
    // filter2D(image, filtered_image, -1 , Mat::ones(1,1,CV_64F), Point(-1, -1), 0, BORDER_DEFAULT);
    // filter2D(filtered_image, image, -1 , blacking*100, Point(-1, -1), 0, BORDER_DEFAULT);
    // filter2D(image, filtered_image, -1 , laplassian_of_gaussian, Point(-1, -1), 0, BORDER_DEFAULT);
    // filter2D(filtered_image, image, -1 , laplassian_of_gaussian, Point(-1, -1), 0, BORDER_DEFAULT);
    // filter2D(image, filtered_image, -1 , laplassian_of_gaussian, Point(-1, -1), 0, BORDER_DEFAULT);

    // filter2D(filtered_image, image, -1 , Mat::ones(5,5, CV_64F)*0.25, Point(-1, -1), 0, BORDER_DEFAULT);


    return filtered_image*100;
    // imshow("Original", image);
    // imshow("Filtered", identity);
    // waitKey();
    // imwrite("identity.jpg", identity);
    // destroyAllWindows();

    // waitKey();
    // destroyAllWindows();
}