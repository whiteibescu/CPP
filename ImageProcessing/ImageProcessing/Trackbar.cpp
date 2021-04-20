#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

string title = "¹à±âº¯°æ", bar_name = "¹à±â°ª";
Mat image;
void onChange(int value, void* userdata)
{
	int add_value = value - 130;
	cout << "Ãß°¡ È­¼Ò°ª" << add_value << endl;

	Mat tmp = image + add_value;
	imshow(title, tmp);
}

void onMouse(int event, int x, int y, int flags, void* param)
{
	if (event == EVENT_RBUTTONDOWN)
	{
		add(image, 10, image);
		setTrackbarPos(bar_name, title, image.at<uchar>(0));
		imshow(title, image);
	}
	else if (event == EVENT_LBUTTONDOWN)
	{
		subtract(image, 10, image);
		setTrackbarPos(bar_name, title, image.at<uchar>(0));
		imshow(title, image);
	}
}




int main()
{
	int value = 128;
	image = Mat(300, 400, CV_8UC1, Scalar(120));

	namedWindow(title, WINDOW_AUTOSIZE);
	createTrackbar("¹à±â°ª", title, &value, 255, onChange);
	setMouseCallback(title, onMouse, 0);

	imshow(title, image);
	waitKey(0);
	return 0;
}


