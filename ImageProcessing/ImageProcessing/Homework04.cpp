#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat image(800, 1200, CV_8UC3);
Scalar blue(255, 0, 0);
Scalar red(0, 0, 255);
string title = "문제 3번";
int key = waitKey(100);

void onMouse(int event, int x, int y, int flags, void* params)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		if (flags & EVENT_FLAG_SHIFTKEY)
		{
			cout << "일단 왼쪽 클릭 된다" << endl;
			cout << "좌표는 " << x << y << endl;
			Point pt1(x, y);
			circle(image, pt1, 20, blue, 2);
			imshow(title, image);
		}
		else
		{
			cout << "오른쪽 클릭했지? " << endl;
			Point pt1(x, y);
			Rect rect(pt1, Size(30, 30));
			rectangle(image, rect, red, 2);
			imshow(title, image);
		}
	}
}

int main()
{
	namedWindow(title, WINDOW_NORMAL);
	resizeWindow(title, 1200, 800);
	setMouseCallback(title, onMouse, 0);
	imshow(title, image);
	waitKey(0);
	return 0;
}
