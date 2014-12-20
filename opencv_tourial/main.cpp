#include <iostream>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <strings.h>

using namespace std;
using namespace cv;
const string trackbarWindowName = "Trackbars";
int H_MIN = 0;
int H_MAX = 256;
int S_MIN = 0;
int S_MAX = 256;
int V_MIN = 0;
int V_MAX = 256;
const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 480;
void on_trackbar( int, void* )
{//This function gets called whenever a
    // trackbar position is changed





}
void createTrackbars()
{
    namedWindow(trackbarWindowName,0);
    char trackBarname[50];
    sprintf(trackBarname,"H_MIN",H_MIN);
    sprintf( trackBarname, "H_MAX", H_MAX);
    sprintf( trackBarname, "S_MIN", S_MIN);
    sprintf( trackBarname, "S_MAX", S_MAX);
    sprintf( trackBarname, "V_MIN", V_MIN);
    sprintf( trackBarname, "V_MAX", V_MAX);
    createTrackbar( "H_MIN", trackbarWindowName, &H_MIN, H_MAX, on_trackbar );
    createTrackbar( "H_MAX", trackbarWindowName, &H_MAX, H_MAX, on_trackbar );
    createTrackbar( "S_MIN", trackbarWindowName, &S_MIN, S_MAX, on_trackbar );
    createTrackbar( "S_MAX", trackbarWindowName, &S_MAX, S_MAX, on_trackbar );
    createTrackbar( "V_MIN", trackbarWindowName, &V_MIN, V_MAX, on_trackbar );
    createTrackbar( "V_MAX", trackbarWindowName, &V_MAX, V_MAX, on_trackbar );
}

int main()
{
    Mat camaraFeel;
    Mat threshold,HSV;
    createTrackbars();
    VideoCapture cap;
    //thu mo camera
    if(!cap.open(0))
    {
        cout<< "Can't open camera!"<< endl;
        return -1;
    }
    cap.set(CV_CAP_PROP_FRAME_WIDTH,FRAME_WIDTH);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT,FRAME_HEIGHT);
    cap.read(camaraFeel);
    while(1)
    {
        cap.read(camaraFeel);
        cvtColor(camaraFeel,HSV,COLOR_RGB2HSV);
        inRange(HSV,Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX),threshold);
        imshow("threshold",threshold);
        imshow("My camera",camaraFeel);
        //delay 30ms so that screen can refresh.
        //image will not appear without this waitKey() command
        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }

    return 0;
}


