#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat filter(Mat image)
{
    // Mat image = imread("image.jpeg");
    Mat sharpening = (Mat_<double>(3,3) <<  0, 0, 0,
                                            0, 1, 0,
                                            0, 0, 0);
    Mat filtered_image; 
    filter2D(image, filtered_image, -1 , sharpening, Point(-1, -1), 0, BORDER_DEFAULT);
    for (int i = 0; i < filtered_image.rows; i++)
    {
        for (int j = 0; j < filtered_image.cols; j++)
        {
            Vec3b& color = filtered_image.at<Vec3b>(i, j);
            if (color[0] + color[1] + color[2] > 50)
            {
                color[0] = 255;
                color[1] = 255;
                color[2] = 255;
            } else 
            {
                color[0] = 0;
                color[1] = 0;
                color[2] = 0;
            }
            // filtered_image.at<Vec3d>(Point(i, j)) = color;
        }
    }

    return filtered_image;
}