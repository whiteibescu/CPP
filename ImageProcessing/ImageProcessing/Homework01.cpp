#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Scalar red(0, 0, 255);
	Mat image(600, 400, CV_8UC3, Scalar(255, 255, 255));
	Point pt1(100, 100);
	Rect rect(pt1, Size(200, 300));
	rectangle(image, rect, red, 2);
	imshow("»ç°¢Çü", image);
	waitKey(0);
}

