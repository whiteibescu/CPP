#include <stdio.h>
#include <iostream>


#include <opencv2/opencv.hpp>
#include <stdlib.h>



using namespace std;
using namespace cv;



int main()
{
    char buffer;

    Mat img;

    VideoCapture capture(0);

    CascadeClassifier face_classifier;

    //face_classifier.load("C:/opencv348/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml");

    // ***�����η� ������ opencv���� haarcascade_frontalface_alt2.xml ���� ��� �����ֱ�***
    face_classifier.load("C:/Opencv/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml");

    Mat frame;



    if (!capture.isOpened()) {

        std::cerr << "Could not open camera" << std::endl;

        return -1;

    }



    while (1) { //���¿� ������ ��� sendCommand()�� ���� ��������� �����͸� �����Ѵ�. ���ۿ� ���� �� ��� failed �޽����� ����Ѵ�.


        bool frame_valid = true;

        capture >> frame;
        try {


            // get a new frame from webcam

            capture >> frame;


        }
        catch (Exception& e) {


            cerr << "Exception occurred. Ignoring frame... " << e.err << std::endl;

            frame_valid = false;


        }

        if (frame_valid) {

            try {

                Mat grayframe;

                cvtColor(frame, grayframe, CV_BGR2GRAY);

                equalizeHist(grayframe, grayframe);

                vector<Rect> faces;


                face_classifier.detectMultiScale(grayframe, faces,

                    1.1, // increase search scale by 10% each pass

                    3,   // merge groups of three detections

                    CV_HAAR_FIND_BIGGEST_OBJECT | CV_HAAR_SCALE_IMAGE,

                    Size(30, 30)

                );


                Mat img_mosaic;
                Mat frame_original;
                frame.copyTo(frame_original);

                for (int i = 0; i < faces.size(); i++) {

                    Point lb(faces[i].x + faces[i].width, faces[i].y + faces[i].height);

                    Point tr(faces[i].x, faces[i].y);

                    img_mosaic = frame(Rect(lb, tr));
                    Mat img_temp;

                    resize(img_mosaic, img_temp, Size(img_mosaic.rows / 8, img_mosaic.cols / 8));
                    resize(img_temp, img_mosaic, Size(img_mosaic.rows, img_mosaic.cols));
                    rectangle(frame, lb, tr, Scalar(100 * (i - 2), 255, 255 * i), 3, 4, 0);
                    rectangle(frame_original, lb, tr, Scalar(100 * (i - 2), 255, 255 * i), 3, 4, 0);

                }

                imshow("mosaic", frame);
                imshow("webcam", frame_original);

            }

            catch (Exception& e) {

                cerr << "Exception occurred. Ignoring frame... " << e.err << std::endl;

            }

        }

        if (waitKey(30) == 27) break;

    }

    return 0;

}