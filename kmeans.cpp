#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace cv;
using namespace std;

Mat draw_mark(Mat image, Vec2i point)
{
    int l = image.rows;
    int h = image.cols;
    int radius = 10;
    Vec3i left_upper;
    Vec3i right_bottom;

    if (point[0] - radius >= 0)
        left_upper[0] = point[0]-radius;
    else
        left_upper[0] = 0;
    
    if (point[0] + radius < l)
        right_bottom[0] = point[0]+radius;
    else
        right_bottom[0] = l;

    if (point[1] - radius >= 0)
        left_upper[1] = point[1]-radius;
    else
        left_upper[1] = 0;
    
    if (point[1] + radius < h)
        right_bottom[1] = point[1]+radius;
    else
        right_bottom[1] = l;

    for (int i = left_upper[0]; i < right_bottom[0]; i++)
        for (int j = left_upper[1]; j < right_bottom[1]; j++)
            image.at<Vec3b>(i, j) = Vec3b(0, 0, 255);
    return image;
}

Mat kmeans_filter(Mat image)
{
    int length = image.rows;
    int height = image.cols;
    Vec2i k = {rand() % length, rand() % height};
    Vec2i summ = {0, 0};
    // Vec2i mean = {0, 0};
    int a = 0;
    int b = 0;
    int n = 0;

    for (int i = 0; i < image.rows; i++)
        for (int j = 0; j < image.cols; j++)
            if (image.at<Vec3b>(i, j) == Vec3b(255, 255, 255))
                n++;
    if (n<500) return image;
    // cout << n << endl;
    // for (int c = 0; c < 100; c++)
    {
        summ = {0, 0};
        for (int i = 0; i < image.rows; i++)
        {
            for (int j = 0; j < image.cols; j++)
            {
                if (image.at<Vec3b>(i, j) == Vec3b(255, 255, 255))
                {
                    summ[0] += i;
                    summ[1] += j; 
                }
            }
        }

        k[0] = (summ[0]/n);
        k[1] = (summ[1]/n);    
        // cout << k << endl;
    }
    return draw_mark(image, k);;

}

