#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat lena_gray = imread("lena.png", 0);
    Mat lena_color = imread("lena.png");
    Mat dst;

    // gray thresh
    threshold(lena_gray, dst, 128, 200, THRESH_BINARY);
    imshow("grayscale_THRESH_BINARY", dst);

    threshold(lena_gray, dst, 128, 200, THRESH_BINARY_INV);
    imshow("grayscale_THRESH_BINARY_INV", dst);

    threshold(lena_gray, dst, 128, 200, THRESH_TOZERO);
    imshow("grayscale_THRESH_TOZERO", dst);

    threshold(lena_gray, dst, 128, 200, THRESH_TOZERO_INV);
    imshow("grayscale_THRESH_TOZERO_INV", dst);

    threshold(lena_gray, dst, 128, 200, THRESH_TRUNC);
    imshow("grayscale_THRESH_TRUNC", dst);

    // color thresh
    threshold(lena_color, dst, 128, 200, THRESH_BINARY);
    imshow("color_THRESH_BINARY", dst);

    threshold(lena_color, dst, 128, 200, THRESH_BINARY_INV);
    imshow("color_THRESH_BINARY_INV", dst);

    threshold(lena_color, dst, 128, 200, THRESH_TOZERO);
    imshow("color_THRESH_TOZERO", dst);

    threshold(lena_color, dst, 128, 200, THRESH_TOZERO_INV);
    imshow("color_THRESH_TOZERO_INV", dst);

    threshold(lena_color, dst, 128, 200, THRESH_TRUNC);
    imshow("color_THRESH_TRUNC", dst);

    waitKey(0);
    return 0;
}