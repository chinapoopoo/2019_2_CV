#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat lena_gray = imread("lena.png", 0);
    Mat dst;

    adaptiveThreshold(lena_gray, dst, 200, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, 10);
    imshow("3", dst);

    adaptiveThreshold(lena_gray, dst, 200, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 5, 10);
    imshow("5", dst);

    adaptiveThreshold(lena_gray, dst, 200, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 7, 10);
    imshow("7", dst);

    waitKey(0);
    return 0;
}