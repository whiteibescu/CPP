#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat image(400, 600, CV_8UC3);
	image.setTo(Scalar(255, 255, 255));

	Point center = Point(image.cols / 2, image.rows / 2);
	Size cir_size1(50, 50), cir_size2(100, 100);
	Scalar blue(255, 0, 0), red(0, 0, 255);

	ellipse(image, center, cir_size2, 0, 0, 180, blue, -1);
	ellipse(image, center, cir_size2, 0, 180, 360, red, -1);
	ellipse(image, Point(center.x - 50, center.y), cir_size1, 0, 0, 180, red, -1);
	ellipse(image, Point(center.x + 50, center.y), cir_size1, 0, 180, 360, blue, -1);

	imshow("ÅÂ±Ø±â", image);
	waitKey(-1);
}

