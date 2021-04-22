#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat img_blur;
	Mat img = imread("../Lecture_04_22/image.jpg", 1);
	Size size(0, 0);
	resize(img, img, size, 0.3, 0.3, INTER_LINEAR);


	GaussianBlur(img, img_blur, Size(7, 7), 0);


	imshow("원본", img);
	imshow("가오시안Blur", img_blur);
	waitKey(0);

	return 0;
}