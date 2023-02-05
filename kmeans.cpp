#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
using namespace cv;
using namespace std;

Mat draw_mark(Mat image, Vec2i point)
{
    int l = image.rows;
    int h = image.cols;
    int radius = 5;
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

int distance(Vec2i a, Vec2i b)
{
    return (int)sqrt(pow(b[0]-a[0], 2) + pow(b[1]-a[1], 2));
}

int find_nearest_centroid(Vec2i point, vector<Vec2i> centroids)
{
    int min_distance = 100000;
    int min_index = 0;
    int counter = -1;
    for(auto& centroid : centroids)
    {
        counter++;
        if (distance(point, centroid) < min_distance)
        {
            min_distance = distance(point, centroid);
            min_index = counter;
        }
    }
    return min_index;
}

Mat kmeans_filter(Mat image, Mat original)
{
    // return original;
    int length = image.rows;
    int height = image.cols;

    int n = 0;
    int k = 20;
    
    vector<Vec2i> centroids(k);
    for (auto& e : centroids)
        e = {rand() % length, rand() % height};

    vector<Vec2i> centroids_sum(k);
    
    vector<int> centroid_points_num(k);
    for (auto& e : centroid_points_num)
        e = 0;

    for (int y = 0; y < image.rows; y++)
        for (int x = 0; x < image.cols; x++)
            if (image.at<Vec3b>(y, x) == Vec3b(255, 255, 255))
                n++;

    if (n < 100) return original;

    int point_nearest_centroid[n] = {0};

    int point;

    for (int c = 0; c < 10; c++) //convergence cycle
    {
        point = 0;

        for (auto& e : centroids_sum)
            e = {0, 0};
        
        for (auto& e : centroid_points_num)
            e = 0;

        for (int y = 0; y < image.rows; y++)
        {
            for (int x = 0; x < image.cols; x++)
            {
                if (image.at<Vec3b>(y, x) == Vec3b(255, 255, 255))
                {
                    point_nearest_centroid[point] = find_nearest_centroid(Vec2i(y, x), centroids);
                    centroids_sum[point_nearest_centroid[point]][0] += y;
                    centroids_sum[point_nearest_centroid[point]][1] += x;
                    centroid_points_num[point_nearest_centroid[point]]++;
                    point++;
                }
            }
        }
        for (int d = 0; d < k; d++)
        {
            if (centroid_points_num[d] < 50)
            {
                centroids[d][0] = -100;
                centroids[d][1] = -100;
                continue;
            } 
            // cout << centroid_points_num[d] << endl;
            centroids[d][0] = (centroids_sum[d][0])/centroid_points_num[d];
            centroids[d][1] = (centroids_sum[d][1])/centroid_points_num[d];
            
        }

        // k[0] = (summ[0]/n);
        // k[1] = (summ[1]/n);    
        // cout << k << endl;
    }

    for(auto& e : centroids)
        original = draw_mark(original, e);
    return original;
}

