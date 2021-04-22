#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
// rotation() �Լ��� �̿��ؼ� ���� ������ �Է� �޾� 300, 100 ��ǥ�� �������� 30�� ȸ��
// affine ��ȯ ����� �̿�
// �� �Լ��� ���� ������ �ǵ���

//ȭ�Ұ� �缱�� ����
uchar bilinear_value(Mat img, int x, int y) {
	// �Է¿��� ���� ����� �ʵ���
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

// �������� ȸ�� ��ȯ
void rotation(Mat img, Mat& dst, double dgree, Point pt) {
	double radian = dgree / 180 * CV_PI; // ȸ�� ����
	double sin_value = sin(radian);
	double cos_value = cos(radian);

	Rect rect(Point(0, 0), img.size()); // �Է� ���� ���� �簢��
	dst = Mat(img.size(), img.type(), Scalar(0)); // ���� ����

	// �������� ��ȸ (������ ���)
	for (int i = 0; i < dst.rows; i++) {
		for (int j = 0; j < dst.cols; j++) {
			int jj = j - pt.x;
			int ii = i - pt.y;
			double x = jj * cos_value + ii * sin_value + pt.x; //ȸ�� ��ȯ ����
			double y = -jj * sin_value + ii * cos_value + pt.y; //������ ��� ����

			//�Է� ���� ���� Ȯ��
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
	imshow("dst1-30�� ȸ��", dst1);
	waitKey();
}