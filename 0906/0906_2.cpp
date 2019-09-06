#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image = imread("sun.jpg");
    Rect rect(50, 50, 350, 150);
    Mat rect_roi = image(rect);

    cout << image.size().height << ", " << image.size().width << endl;

    rect_roi.setTo(Scalar(255, 255, 0));

    imshow("original", image);
    imshow("ROI", rect_roi);

    waitKey(0);
    return 0;
}