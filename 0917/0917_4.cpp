#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap("NTH3.mp4");
    Mat frame;

    double fps = cap.get(CAP_PROP_FPS);
    double delay = 1000 / fps;
    int total_frame = cap.get(CAP_PROP_FRAME_COUNT);

    int count = 0;

    while (1)
    {
        cap >> frame;
        if (frame.empty())
            break;

        putText(frame, format("%d / %d", ++count, total_frame), Point(50, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 4);

        imshow("frame", frame);
        waitKey(delay);
    }
}