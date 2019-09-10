#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat apple = imread("apple.jpg");

    imshow("original", apple);
    cvtColor(apple, apple, CV_BGR2YCrCb);
    inRange(apple, Scalar(0, 0, 0), Scalar(255, 160, 126), apple);
    imshow("result", apple);

    waitKey(0);
    return 0;
}