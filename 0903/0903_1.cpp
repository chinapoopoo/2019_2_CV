#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image_color, image_gray;
    image_color = imread("lena.png", IMREAD_COLOR);
    image_gray = imread("lena.png", 0);

    imshow("lena_color", image_color);
    imshow("lena_gray", image_gray);
    waitKey(0);

    return 0;
}