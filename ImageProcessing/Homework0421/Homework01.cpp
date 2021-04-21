#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


int main()
{
	Mat merged_image;
	Mat image = imread("../Homework0421/logo.jpg", IMREAD_COLOR);
	Mat matriximage = cv::Mat::zeros(image.size(), CV_8UC1);
	CV_Assert(image.data);
	
	Mat bgr[3];
	split(image, bgr);
	Mat R[] = { matriximage, matriximage, bgr[2] };
	Mat G[] = { matriximage, bgr[1], matriximage };
	Mat B[] = { bgr[0], matriximage, matriximage };
	merge(R, 3, bgr[2]);
	merge(G, 3, bgr[1]);
	merge(B, 3, bgr[0]);

	imshow("오리지널영상", image);
	imshow("blue채널", bgr[0]);
	imshow("green채널", bgr[1]);
	imshow("red채널", bgr[2]);

	waitKey(0);
	return 0;
}