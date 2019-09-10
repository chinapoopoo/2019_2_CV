#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat apple = imread("apple.jpg");
    Mat fracture = imread("Fracture_spine.png");
    Mat dst;

    add(apple, fracture, dst);
    imshow("add", dst);

    waitKey(0);
    return 0;
}