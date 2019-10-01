#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat drawHistogram(Mat src);

int main()
{
    Mat image = imread("apple.jpg");
    Mat hist_equalized_image;
    Mat hist_equalized_graph;
    Mat channels[3];

    split(image, channels);

    equalizeHist(channels[0], channels[0]);
    equalizeHist(channels[1], channels[1]);
    equalizeHist(channels[2], channels[2]);

    merge(channels, 3, hist_equalized_image);

    hist_equalized_graph = drawHistogram(hist_equalized_image);

    imshow("Original", image);
    imshow("Equalized", hist_equalized_image);
    imshow("Graph", hist_equalized_graph);

    waitKey(0);
    return 0;
}

Mat drawHistogram(Mat src)
{
    Mat hist, histImage;

    int i, hist_w, hist_h, bin_w, histSize;
    float range[] = {0, 256};
    const float *histRange = {range};
    int channel[1] = {2};

    hist_w = 512;
    hist_h = 400;
    histSize = 8;
    bin_w = cvRound((double)hist_w / histSize);

    cout << "여기";
    calcHist(&src, 1, channel, Mat(), hist, 1, &histSize, &histRange);
    cout << "여기2";

    histImage = Mat(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

    normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    for (i = 0; i < histSize; i++)
        rectangle(histImage, Point(bin_w * i, hist_h), Point(bin_w * i + hist_w / histSize, hist_h - cvRound(hist.at<float>(i))), Scalar(0, 0, 0), -1, CV_AA, 0);

    return histImage;
}