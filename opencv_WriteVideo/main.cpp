#include <QCoreApplication>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    VideoCapture cap(0);
    if(cap.isOpened())
    {
        namedWindow("Myvideo",CV_WINDOW_AUTOSIZE);
        double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);//get width size
        double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
        cout <<"Frame size " << dWidth << "x"<<dHeight<<endl;
        Size frameSize(static_cast<int>(dWidth),static_cast<int>(dHeight));
        VideoWriter oVideoWrite("/home/xdien/myOut.avi",CV_FOURCC('P','I','M','1'),20,frameSize,true);//initialize the Videowrite object
        if(!oVideoWrite.isOpened())
        {
            cout << "Error: File to write the video"<<endl;
            return -1;
        }
        while(1)
        {
            Mat frame;
            bool bSucces = cap.read(frame);// read a new frame from video
            if(!bSucces)
            {
                cout << "ERROR: Cannot read a frame from video file" << endl;
                break;
            }
            oVideoWrite.write(frame);
            imshow("MyVdideo",frame);
            if(waitKey(10) == 27)
            {
                cout <<"esc key pressed by user" << endl;
                break;
            }
        }
        return 0;
    }
    else
    {
        cout << "Can't open camera! "<<endl;
        return -1;
    }
}
