#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void print_matInfo(string name, Mat img)
{
	string filename = "../image/example.jpg";
	Mat gray2gray = imread(filename, IMREAD_GRAYSCALE);
	Mat gray2color = imread(filename, IMREAD_COLOR);
}