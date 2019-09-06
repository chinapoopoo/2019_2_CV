#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image, image_hsi;
    Mat hsi_channels[3];

    image = imread("lena.png", IMREAD_COLOR);
    cvtColor(image, image_hsi, CV_BGR2HSV);

    split(image_hsi, hsi_channels);

    imshow("lena_color", hsi_channels[1]);
    waitKey(0);

    return 0;
}