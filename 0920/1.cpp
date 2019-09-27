#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat image_at = imread("lena.png");
	Mat image_dm = image_at.clone();

	//case 1: at operator
	for (int y = 0; y < image_at.rows; y++) {
		for (int x = 0; x < image_at.cols; x++) {
			if (y % 2 == 0) {
				image_at.at<Vec3b>(y, x)[0] = 0;
				image_at.at<Vec3b>(y, x)[1] = 0;
				image_at.at<Vec3b>(y, x)[2] = 255;
			}
		}
	}

	//case 2: data member function
	uchar* data = (uchar*)image_dm.data;
	int channels = image_dm.channels();
	for (int y = 0; y < image_dm.rows; y++) {
		for (int x = 0; x < image_dm.cols; x++) {
			if (y % 2 == 0) {
				data[(y * image_dm.cols + x) * channels + 0] = 0;
				data[(y * image_dm.cols + x) * channels + 1] = 0;
				data[(y * image_dm.cols + x) * channels + 2] = 255;
			}
		}
	}
	imshow("at operator", image_at);
	imshow("data member function", image_dm);
	waitKey();
}