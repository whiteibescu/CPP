#include <opencv2/highgui.hpp>

void main()
{
	cv::Mat image(200, 400, CV_8UC1, cv::Scalar(100));
	cv::imshow("���󺸱�", image);
	cv::waitKey(0);
}