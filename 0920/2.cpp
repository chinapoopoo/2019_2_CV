#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat image = imread("lena.png");

	MatIterator_<Vec3b> it, end;

	for (it = image.begin<Vec3b>(), end = image.end<Vec3b>(); it != end; ++it)
		(*it)[0] = 255;

	imshow("image", image);
	waitKey();
}