#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat frame;
    VideoCapture cap;
    cap.open("background.mp4");

    while (1)
    {
        cap >> frame;
        if (frame.empty())
        {
            cout << "end of video" << endl;
            break;
        }
        imshow("video", frame);
        waitKey(33);
    }
    return 0;
}