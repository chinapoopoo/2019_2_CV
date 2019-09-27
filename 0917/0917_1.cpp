#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat lena = imread("lena.png");
    Rect rect = Rect(200, 200, 200, 200);
    rectangle(lena, rect, Scalar(0, 255, 0), 4, 8, 0);

    imshow("lena", lena);
    waitKey(0);
    return 0;
}