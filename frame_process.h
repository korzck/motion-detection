#include <opencv2/opencv.hpp>
#include "kmeans.h"
#include <iostream>

using namespace std;
using namespace cv;

Mat black_and_white(Mat image)
{
    for (int y = 0; y < image.rows; y++)
    {
        for (int x = 0; x < image.cols; x++)
        {
            Vec3b& color = image.at<Vec3b>(y, x);
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
        }
    }
    return image;
}

Mat filter(Mat difference, Mat original)
{
    Mat sharpening = (Mat_<double>(3,3) <<  0, 0, 0,
                                            0, 1, 0,
                                            0, 0, 0);
    difference = black_and_white(difference);
    filter2D(difference, difference, -1 , sharpening, Point(-1, -1), 0, BORDER_DEFAULT);
    difference = black_and_white(difference);

    
    for (int y = 1; y < difference.rows-1; y++)
    {
        for (int x = 1; x < difference.cols-1; x++)
        {
            if (difference.at<Vec3b>(y, x) == Vec3b(255, 255, 255))
            {
                if (
                    difference.at<Vec3b>(y, x+1) == Vec3b(0, 0, 0) &&
                    difference.at<Vec3b>(y, x-1) == Vec3b(0, 0, 0) &&
                    difference.at<Vec3b>(y+1, x) == Vec3b(0, 0, 0) &&
                    difference.at<Vec3b>(y+1, x+1) == Vec3b(0, 0, 0) &&
                    difference.at<Vec3b>(y+1, x-1) == Vec3b(0, 0, 0) &&
                    difference.at<Vec3b>(y-1, x) == Vec3b(0, 0, 0) &&
                    difference.at<Vec3b>(y-1, x+1) == Vec3b(0, 0, 0) &&
                    difference.at<Vec3b>(y-1, x-1) == Vec3b(0, 0, 0)
                )
                {
                    difference.at<Vec3b>(y, x) = Vec3b(0, 0, 0);
                }
            }
        }
    }

    return kmeans_filter(difference, original);
}
