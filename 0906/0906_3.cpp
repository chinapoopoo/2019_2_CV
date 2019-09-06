#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat frame, frame_converted;
    VideoCapture cap;
    cap.open("night.mp4");

    while (1)
    {
        cap >> frame;
        if (frame.empty())
        {
            cout << "end of video" << endl;
            break;
        }
        convertScaleAbs(frame, frame_converted, 5, 10);
        imshow("night", frame_converted);
        waitKey(33);
    }
    return 0;
}