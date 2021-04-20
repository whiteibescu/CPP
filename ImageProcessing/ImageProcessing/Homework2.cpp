#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void onMouse(int, int, int, int, void*);

void onMouse(int event, int x, int y, int flags, void* params)
{
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		cout << "일단 왼쪽 클릭 된다" << endl;
		cout << "좌표는 " << x << y << endl;
		break;
	case EVENT_FLAG_RBUTTON:
		cout << "오른쪽 클릭했지? " << endl;
		Point pt1(x, y);
		Rect rect(pt1, Size(200, 300));
		break;
	}
}

void problemNum01()
{
	Scalar red(0, 0, 255);
	Mat image(600, 400, CV_8UC3, Scalar(255, 255, 255));
	Point pt1(100, 100);
	Rect rect(pt1, Size(200, 300));
	rectangle(image, rect, red, 2);
	imshow("사각형", image);
	waitKey(0);	
}

void problemNum04()
{
	Scalar red(0, 0, 255);
	Mat image(600, 400, CV_8UC3, Scalar(255, 255, 255));
	Point pt1(100, 100);
	Rect rect(pt1, Size(200, 300));

	rectangle(image, rect, red, 2);

	imshow("사각형", image);
	waitKey(0);
}

void problemNum03()
{
	string title = "문제 3번";
	Mat image(800, 1200, CV_8UC1, Scalar(255));

	namedWindow(title, WINDOW_NORMAL);
	resizeWindow(title, 1200, 800);

	imshow(title, image);


	setMouseCallback(title, onMouse, 0);
	waitKey(0);
}


void exampledef()
{

}
int main()
{
	problemNum03();
	return 0;
}