#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat light = imread("reverse_light_1.jpg", 0);
    Mat light_scale;
    Mat light_gamma;
    MatIterator_<uchar> it, end;
    float gamma = 2;
    unsigned char pix[256];

    for (int i = 0; i < 256; i++)
        pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);

    light_scale = light.clone();

    for (it = light_scale.begin<uchar>(), end = light_scale.end<uchar>(); it != end; it++)
        *it = saturate_cast<uchar>(*it * 2);

    light_gamma = light.clone();

    for (it = light_gamma.begin<uchar>(), end = light_gamma.end<uchar>(); it != end; it++)
        *it = pix[(*it)];

    imshow("light", light);
    imshow("light_scale", light_scale);
    imshow("light_gamma", light_gamma);

    waitKey(0);
    return 0;
}