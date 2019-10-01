#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat drawHistogram(Mat src);

int main()
{
    Mat image = imread("Moon.png", 0);
    Mat hist_graph = drawHistogram(image);


    imshow("Moon", image);
    imshow("Graph", hist_graph);

    waitKey(0);
    return 0;
}

Mat drawHistogram(Mat src) {
    Mat hist, histImage;

    int i, hist_w, hist_h, bin_w, histSize;
    float range[] = { 0, 256 };
    const float* histRange = { range };

    hist_w = 512;
    hist_h = 400;
    histSize = 16;
    bin_w = cvRound((double) hist_w / histSize);

    calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange);

    histImage = Mat(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

    normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    for(i = 0; i < histSize; i++)
        rectangle(histImage, Point(bin_w * i, hist_h), Point(bin_w * i + hist_w / histSize, hist_h - cvRound(hist.at<float>(i))), Scalar(0, 0, 0), -1, CV_AA, 0);
    
    return histImage;
}