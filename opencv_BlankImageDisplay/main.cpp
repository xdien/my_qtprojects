#include <QCoreApplication>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    Mat img(300,400,CV_8UC3,Scalar(0,128,255));
    //namedWindow("Colorimg!",CV_WINDOW_AUTOSIZE);
    imshow("My windows",img);
    waitKey(0);
    destroyWindow("Colorimg");
    return 0;
}
