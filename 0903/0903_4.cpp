#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image(1080, 1920, CV_8UC3, Scalar(0, 255, 255));
    imshow("matrix", image);

    waitKey(0);
    return 0;
}