#include <QCoreApplication>

//objectTrackingTutorial.cpp

//Written by  Kyle Hounslow 2013

//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software")
//, to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
//and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//IN THE SOFTWARE.

#include <sstream>
#include <string>
#include <iostream>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <stdio.h>

using namespace cv;
using namespace std;
//initial min and max HSV filter values.
//these will be changed using trackbars
int H_MIN = 0;
int H_MAX = 256;
int S_MIN = 0;
int S_MAX = 256;
int V_MIN = 0;
int V_MAX = 256;
//default capture width and height
const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 480;
//names that will appear at the top of each window
const string windowName = "Original Image";
CascadeClassifier face_cascade;
string face_cascade_name = "/home/xdien/QTprojects/tutorial-haartraining/data/haarcascades/haarcascade_frontalface_alt2.xml";
int main(int argc, char* argv[])
{
    if (!face_cascade.load(face_cascade_name))
        {
            printf("--(!)Error loading\n");
            return (-1);
        };
    //if we would like to calibrate our filter values, set to true.
    //Matrix to store each frame of the webcam feed
    Mat cameraFeed;
    //video capture object to acquire webcam feed
    VideoCapture capture;
    //open capture object at location zero (default location for webcam)
    capture.open(0);
    //set height and width of capture frame
    capture.set(CV_CAP_PROP_FRAME_WIDTH,FRAME_WIDTH);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,FRAME_HEIGHT);
    std::vector<Rect> faces;
    Mat frame_gray;
    cv::Rect roi_b;
    cv::Rect roi_c;
    //start an infinite loop where webcam feed is copied to cameraFeed matrix
    //all of our operations will be performed within this loop
    while(1){
        //store image to matrix
        capture.read(cameraFeed);
        cvtColor(cameraFeed, frame_gray, COLOR_BGR2GRAY);
        equalizeHist(frame_gray, frame_gray);

        // Detect faces
        face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

        // Set Region of Interest
        size_t ic = 0; // ic is index of current element
        int ac = 0; // ac is area of current element

        size_t ib = 0; // ib is index of biggest element
        int ab = 0; // ab is area of biggest element

        for (ic = 0; ic < faces.size(); ic++) // Iterate through all current elements (detected faces)

        {

            roi_c.x = faces[ic].x;
            roi_c.y = faces[ic].y;
            roi_c.width = (faces[ic].width);
            roi_c.height = (faces[ic].height);

            ac = roi_c.width * roi_c.height; // Get the area of current element (detected face)

            roi_b.x = faces[ib].x;
            roi_b.y = faces[ib].y;
            roi_b.width = (faces[ib].width);
            roi_b.height = (faces[ib].height);

            ab = roi_b.width * roi_b.height; // Get the area of biggest element, at beginning it is same as "current" element

            if (ac > ab)
            {
                ib = ic;
                roi_b.x = faces[ib].x;
                roi_b.y = faces[ib].y;
                roi_b.width = (faces[ib].width);
                roi_b.height = (faces[ib].height);
            }
            Point pt1(faces[ic].x, faces[ic].y); // Display detected faces on main window - live stream from camera
            Point pt2((faces[ic].x + faces[ic].height), (faces[ic].y + faces[ic].width));
            rectangle(cameraFeed, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);
        }

        imshow(windowName,cameraFeed);
        //delay 30ms so that screen can refresh.
        if (waitKey(50) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }
    return 0;
}
