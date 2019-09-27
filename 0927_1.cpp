#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image_gray = imread("Binary.PNG", 0);
    Mat negative_img = image_gray.clone();

    for (int j = 0; j < image_gray.rows; j++)
    {
        for (int i = 0; i < image_gray.cols; i++)
        {
            negative_img.at<uchar>(j, i) = 255 - image_gray.at<uchar>(j, i);
        }
    }

    imshow("Birany", image_gray);
    imshow("Negative", negative_img);

    waitKey(0);
    return 0;
}