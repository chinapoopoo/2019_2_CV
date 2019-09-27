#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat frame;
    Point points[4];
    VideoCapture cap;
    cap.open("road.mp4");

    while (1)
    {
        cap >> frame;

        if (frame.empty())
        {
            cout << "end of video" << endl;
            break;
        }

        points[0] = Point(frame.size().width / 5, 0);
        points[1] = Point(frame.size().width / 3, frame.size().height);
        points[2] = Point(frame.size().width / 3, 0);
        points[3] = Point(frame.size().width / 5, frame.size().height);

        line(frame, points[0], points[1], Scalar(255, 0, 0), 3, 8, 0);
        line(frame, points[2], points[3], Scalar(255, 0, 0), 3, 8, 0);

        imshow("road", frame);
        waitKey(33);
    }
    return 0;
}