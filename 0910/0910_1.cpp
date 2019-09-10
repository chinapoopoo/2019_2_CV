#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat lena = imread("lena.png");
    Mat apple = imread("apple.jpg");
    Mat dst;

    subtract(lena, apple, dst);
    imshow("subtract", dst);

    absdiff(lena, apple, dst);
    imshow("absdiff", dst);

    waitKey(0);
    return 0;
}