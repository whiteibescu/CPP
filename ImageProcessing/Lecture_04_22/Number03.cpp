#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
// rotation() 함수를 이용해서 영상 파일을 입력 받아 300, 100 좌표를 기준으로 30도 회정
// affine 변환 행렬을 이용
// 두 함수가 같은 방향이 되도록

//화소값 양선형 보간
uchar bilinear_value(Mat img, int x, int y) {
	// 입력영상 범위 벗어나지 않도록
	if (x >= img.cols - 1) x--;
	if (y >= img.rows - 1) y--;

	Point pt((int)x, (int)y);
	int A = img.at<uchar>(pt);
	int B = img.at<uchar>(pt + Point(0, 1));
	int C = img.at<uchar>(pt + Point(1, 0));
	int D = img.at<uchar>(pt + Point(1, 1));

	double alpha = y - pt.y;
	double beta = x - pt.x;
	int M1 = A + (int)cvRound(alpha * (B - A));
	int M2 = C + (int)cvRound(alpha * (D - C));
	int P = M1 + (int)cvRound(beta * (M2 - M1));

	return saturate_cast<uchar>(P);
}

// 원점기준 회전 변환
void rotation(Mat img, Mat& dst, double dgree, Point pt) {
	double radian = dgree / 180 * CV_PI; // 회전 각도
	double sin_value = sin(radian);
	double cos_value = cos(radian);

	Rect rect(Point(0, 0), img.size()); // 입력 영상 범위 사각형
	dst = Mat(img.size(), img.type(), Scalar(0)); // 목적 영상

	// 목적영상 순회 (역방향 사상)
	for (int i = 0; i < dst.rows; i++) {
		for (int j = 0; j < dst.cols; j++) {
			int jj = j - pt.x;
			int ii = i - pt.y;
			double x = jj * cos_value + ii * sin_value + pt.x; //회전 변환 수식
			double y = -jj * sin_value + ii * cos_value + pt.y; //역방향 사상 수식

			//입력 영상 범위 확인
			if (rect.contains(Point2d(x, y)))
				dst.at<uchar>(i, j) = bilinear_value(img, x, y);
		}
	}
}

void main() {
	Mat image = imread("../Lecture_04_22/image.jpg", 0);
	CV_Assert(image.data);
	Size size(0, 0);
	resize(image, image, size, 0.2, 0.2, INTER_LINEAR);

	Mat dst1;
	Point center = image.size() / 2;
	rotation(image, dst1, 30, center);

	imshow("image", image);
	imshow("dst1-30도 회전", dst1);
	waitKey();
}