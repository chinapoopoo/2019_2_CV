#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat background(Size(640, 480), CV_8UC3, Scalar(0, 255, 255));

    Point trapezoid[1][4];
    trapezoid[0][0] = Point(100, 100);
    trapezoid[0][1] = Point(120, 100);
    trapezoid[0][2] = Point(140, 200);
    trapezoid[0][3] = Point(80, 200);
    //시계 방향으로 회전
    Point hexagon[1][6];
    hexagon[0][0] = Point(400, 200);
    hexagon[0][1] = Point(500, 200);
    hexagon[0][2] = Point(600, 300);
    hexagon[0][3] = Point(500, 400);
    hexagon[0][4] = Point(400, 400);
    hexagon[0][5] = Point(300, 300);

    const Point *ppt[2] = {trapezoid[0], hexagon[0]};
    int npt[2] = {4, 6};

    fillPoly(background, ppt, npt, 2, Scalar(0), 8);

    imshow("background", background);
    waitKey();
}