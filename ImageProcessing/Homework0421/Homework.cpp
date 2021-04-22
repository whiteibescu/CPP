#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void draw_histo0(Mat hist, Mat& hist_img, Size size = Size(256, 200))
{
    hist_img = Mat(size, CV_8U, Scalar(255));
    normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);

    for (int i = 0; i < hist.cols; i++)
    {
        float start_x = i;
        float end_x = (i + 1);
        Point2f pt1(start_x, 0);
        Point2f pt2(end_x, hist.at <float>(i));

        if (pt2.y > 0)
            rectangle(hist_img, pt1, pt2, Scalar(0));
    }
    flip(hist_img, hist_img, 0);
}

void draw_histo1(Mat hist, Mat& hist_img, Size size = Size(256, 200))
{
    hist_img = Mat(size, CV_8U, Scalar(255));
    normalize(hist, hist, 0, hist_img.cols, NORM_MINMAX);

    for (int i = hist.rows; i > 0; i--)
    {
        float start_y = i;
        float end_y = (i - 1);

        Point2f pt1(0, start_y);
        Point2f pt2(hist.at <float>(i), end_y);

        if (pt2.y > 0)
            rectangle(hist_img, pt1, pt2, Scalar(0));
    }
}

int main()
{
    Mat image = imread("./Nana2.jpg", IMREAD_GRAYSCALE);
    Size size(0, 0);
    resize(image, image, size, 0.2, 0.2, INTER_LINEAR);
    CV_Assert(!image.empty());

    Mat hist, hist_img;
    imshow("image", image);

    reduce(image, hist, 0, REDUCE_SUM, CV_32F); //수직(열)
    draw_histo0(hist, hist_img, image.size());
    imshow("hist_img_0", hist_img);

    reduce(image, hist, 1, CV_REDUCE_SUM, CV_32F); //수평(행)
    draw_histo1(hist, hist_img, image.size());
    imshow("hist_img_1", hist_img);
    waitKey();

    return 0;
}