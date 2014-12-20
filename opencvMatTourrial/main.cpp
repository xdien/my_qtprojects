#include <QCoreApplication>
#include "opencv/cv.h"
#include "opencv2/opencv.hpp"
#include "stdio.h"
#include "opencv/highgui.h"
#include <iostream>

#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>
using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
    /*Mat M(3,2,CV_16UC3,Scalar(0,122,255));
    cout << "M = "<< endl << " " << M << endl << endl;
    int sz[3] = {2,2,2};

    //Mat L(3,sz,CV_8UC(1),Scalar::all(0));
    //cout << "SZ = " << endl << L <<endl;
    //Create a header for an already existing IplImage pointer:
    IplImage *img = cvLoadImage("/home/xdien/Documents/IMAG0030.jpg",1);
    Mat mtx(img);
    M.create(4,4,CV_8UC(2));
    cout << "M = " << endl << " " << M << endl << endl;
    Mat E = Mat::eye(4,4,CV_64F);
    cout << "E = " << endl << E << endl << endl;
    Mat O = Mat::ones(2,2,CV_32F);
    cout << "O = " << endl << O << endl << endl;
    Mat Z = Mat::zeros(3,3,CV_8UC2);
    cout << "Z = " << endl << Z << endl << endl;
    //For small matrices you may use comma separated initializers:
    Mat C = (Mat_<double>(3,3)<< 0,-1,0,-1,5,-2,-3,-1);
    cout << "C = " << endl << C << endl << endl;
    Mat Rowclone = C.row(2).clone();
    cout << "Rowclone = " << endl << Rowclone << endl << endl;*/
        QApplication a(argc, argv);

        QCameraViewfinder * viewFinder;
        QCamera * camera;

    /* This did not help
        QByteArray cameraDevice;
        foreach(const QByteArray &deviceName, QCamera::availableDevices()) {
            if (cameraDevice.isEmpty())
                cameraDevice = deviceName;
        }
    */

        camera = new QCamera(); //(cameraDevice);
        viewFinder = new QCameraViewfinder;

        camera->setViewfinder(viewFinder);
        viewFinder->show();
        camera->start();

        return a.exec();
}
