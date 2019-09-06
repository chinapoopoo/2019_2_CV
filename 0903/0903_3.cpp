#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat frame_faster;
    Mat frame_slower;

    VideoCapture cap_faster;
    VideoCapture cap_slower;

    cap_faster.open("background.mp4");
    cap_slower.open("background.mp4");

    while (1)
    {
        cap_faster >> frame_faster;
        if (frame_faster.empty())
        {
            cout << "end of video" << endl;
            break;
        }
        imshow("faster", frame_faster);
        waitKey(15);
    }

    while (1)
    {
        cap_slower >> frame_slower;
        if (frame_slower.empty())
        {
            cout << "end of video" << endl;
            break;
        }
        imshow("slower", frame_slower);
        waitKey(66);
    }
    return 0;
}