#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat bright = imread("bright.jpg", 0);
    Mat bright_gamma;
    Mat dark = imread("dark.jpg", 0);
    Mat dark_gamma;
    MatIterator_<uchar> it, end;
    unsigned char pix[256];

    for (int i = 0; i < 256; i++)
        pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), 100) * 255.0f);

    bright_gamma = bright.clone();

    for (it = bright_gamma.begin<uchar>(), end = bright_gamma.end<uchar>(); it != end; it++)
        *it = pix[(*it)];

    for (int i = 0; i < 256; i++)
        pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), 0.1) * 255.0f);

    dark_gamma = dark.clone();

    for (it = dark_gamma.begin<uchar>(), end = dark_gamma.end<uchar>(); it != end; it++)
        *it = pix[(*it)];

    imshow("bright", bright);
    imshow("bright_gamma", bright_gamma);
    imshow("dark", dark);
    imshow("dark_gamma", dark_gamma);

    waitKey(0);
    return 0;
}