#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat image = imread("lena.png", 0);

	int value = image.at<uchar>(100, 120);
	cout << "pixel value at (100, 120): " << value << endl;
}