#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("../Homework0421/Nana.jpg", IMREAD_COLOR);
	Size size(0, 0);
	resize(image, image, size, 0.8, 0.8, INTER_LINEAR);

	string title = "보정 전";

	Mat gaussian_blur;
	GaussianBlur(image, gaussian_blur, Size(5, 5), 1);
	//imshow("gaussian blurring", gaussian_blur);

	Mat result;
	addWeighted(image, 1.5, gaussian_blur, -0.5, 0, result);
	imshow("보정 후", result);


	imshow(title, image);
	waitKey(0);
	return 0;

}