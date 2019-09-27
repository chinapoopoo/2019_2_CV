#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat aerial = imread("Aerial_image.png", 0);
    Mat fracture = imread("Fracture_spline.png", 0);
    Mat aerial_gamma, fracture_gamma;
    MatIterator_<uchar> it, end;
    float gamma = 2;
    unsigned char pix[256];

    for (int i = 0; i < 256; i++)
        pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);

    aerial_gamma = aerial.clone();
    fracture_gamma = fracture.clone();

    for (it = aerial_gamma.begin<uchar>(), end = aerial_gamma.end<uchar>(); it != end; it++)
        *it = pix[(*it)];

    for (it = fracture_gamma.begin<uchar>(), end = fracture_gamma.end<uchar>(); it != end; it++)
        *it = pix[(*it)];

    imshow("aerial", aerial);
    imshow("fracture", fracture);
    imshow("aerial_gamma", aerial_gamma);
    imshow("fracture_gamma", fracture_gamma);

    waitKey(0);
    return 0;
}