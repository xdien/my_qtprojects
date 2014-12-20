/*#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
    cv::Mat image = cv::imread("/home/xdien/Pictures/ky-hieu-tay.jpg");
    //cv::Mat image = cv::imread("/mnt/sdcard/Download/25e2313fed378e3f948879cb96971723.jpg");
    cv::Rect rec = cv::Rect(100,10,300,300);
    cv::Mat roi = image(rec);
    //image()
    cv::Mat color(roi.size(), CV_8UC3, cv::Scalar(0, 125, 125));
    double alpha = 0.3;
    cv::addWeighted(color,alpha, roi, 1.0 - alpha , 0.0,roi);
    cv::imshow("image",image);
    cv::waitKey(0);
}

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main( )
{
    Mat src1;
    src1 = imread("/home/xdien/Pictures/thiennhien.jpg", CV_LOAD_IMAGE_COLOR);
    namedWindow( "Original image", CV_WINDOW_AUTOSIZE );
    imshow( "Original image", src1 );

    Mat grey;
    cvtColor(src1, grey, CV_BGR2GRAY);

    Mat sobelx;
    Sobel(grey, sobelx, CV_32F, 1, 0);

    double minVal, maxVal;
    minMaxLoc(sobelx, &minVal, &maxVal); //find minimum and maximum intensities
    cout << "minVal : " << minVal << endl << "maxVal : " << maxVal << endl;

    Mat draw;
    sobelx.convertTo(draw, CV_8U, 255.0/(maxVal - minVal), -minVal * 255.0/(maxVal - minVal));

    namedWindow("image", CV_WINDOW_AUTOSIZE);
    imshow("image", draw);

    waitKey(0);
    return 0;
}

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat src = imread("/home/xdien/Pictures/thiennhien.jpg", 0);

    // Create a structuring element (SE)
    int morph_size = 2;
    Mat element = getStructuringElement( MORPH_RECT, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
    cout<<element;

    Mat dst; // result matrix
    // Apply the specified morphology operation
    for (int i=1;i<10;i++)
    {
    morphologyEx( src, dst, MORPH_TOPHAT, element, Point(-1,-1), i );
    //morphologyEx( src, dst, MORPH_TOPHAT, element ); // here iteration=1
    imshow("source", src);
    imshow("result", dst);
    waitKey(1000);
    }
    return 0;
}

#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace std;
using namespace cv;
Mat equalizeIntensity(const Mat &inputImage);

int main( int argc, char** argv )
{
    Mat src, hsv;
    src=imread("/home/xdien/Pictures/thiennhien.jpg",1);
    hsv = equalizeIntensity(src);

    namedWindow( "Source", 1 );
    imshow( "Source", src );

    namedWindow( "H-S Histogram", 1 );
    imshow( "H-S Histogram",hsv );
    waitKey();
}
Mat equalizeIntensity(const Mat& inputImage)
{
    if(inputImage.channels() >= 3)
    {
        Mat ycrcb;

        cvtColor(inputImage,ycrcb,CV_BGR2YCrCb);

        vector<Mat> channels;
        split(ycrcb,channels);
        cout << "M = " << endl << " " << channels[2] << endl << endl;

        equalizeHist(channels[0], channels[0]);

        Mat result;
        merge(channels,ycrcb);

        cvtColor(ycrcb,result,CV_YCrCb2BGR);

        return result;
    }
    return Mat();
}

#include <iostream>
#include <stdio.h>
#include <cv.h>
#include <highgui.h>

int main(int argc, char * argv[])
{
IplImage* img = cvLoadImage("/home/xdien/Pictures/notphotoshop.jpg");  //Load image file
cvNamedWindow("Trans-in", CV_WINDOW_AUTOSIZE );     //Create input window
cvNamedWindow("Trans-out", CV_WINDOW_AUTOSIZE  );   //Create output window

cvShowImage("Trans-in", img );  //Show input image in input window

//Create space for outputs rgb and its separate channels, r, g and b
IplImage* img0 = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 3);    //rgb
IplImage* r = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);    //r
IplImage* g = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);    //g
IplImage* b = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);    //b

//cvZero(r);
//cvZero(g);
//cvZero(b);

cvSplit(img, b, g, r, NULL);       //OpenCV likes it in BGR format

cvEqualizeHist(r, r );    //equalise r
cvEqualizeHist( g, g );    //equalise g
cvEqualizeHist( b, b );    //equalise b


cvMerge(b, g, r, NULL, img0);  //merge all separate channels together to output image rgb

//cvReleaseImage(&r);
//cvReleaseImage(&g);
//cvReleaseImage(&b);

cvShowImage("Trans-out", img0); //Show output image in output window


cvWaitKey(0);
cvReleaseImage( &img);
cvReleaseImage( &img0);

cvDestroyWindow( "Trans-in");
cvDestroyWindow( "Trans-out");

return 0;
}


#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace std;
using namespace cv;
Mat equalizeIntensity(const Mat &inputImage);
void for_each_pixel(Mat &image, function fn);

void increase_colour_saturation(cv::Mat &image, uchar inc);
int main( int argc, char** argv )
{

    //Read in an image in BGR
    Mat test, img_hsv;
    Mat image_input = imread("/home/xdien/Pictures/notphotoshop.jpg");
    increase_colour_saturation(image_input,10);
    //Split into,  channels
    //cvtColor(image_input, img_hsv, CV_RGB2HSV);
    //vector<Mat> channels;
    //split(image_input, channels);
    //Apply transformations
    //Replace the x by asterixes, but the forum doesn't allow me to use them...
    //Mat Y = (0.257 x channels[2]) + (0.504 x channels[1]) + (0.098 x channels[0]) + 16;
    //Mat U = -(0.148 x channels[2]) - (0.291 x channels[1]) + (0.439 x channels[0]) + 128;
    //Mat V = (0.439 x channels[2]) - (0.368 x channels[1]) - (0.071 x  channels[0]) + 128;

    //mix channels back together
    //Mat result_HSV(image_input.rows, image_input.cols, CV_8UC3);
    //Mat in[] = { channels[1],channels[1], channels[0]};
    //int from_to[] = { 0,0, 1,1, 2,2 };
    //mixChannels( in, 3, &result_HSV, 1, from_to, 3 );
    //inRange(img_hsv, Scalar(110, 130, 100), Scalar(140, 0, 255), test );
    namedWindow( "Source", 1 );
    imshow( "Source", image_input );
    waitKey();
}

void increase_colour_saturation(cv::Mat &image, uchar inc)
{
    cv::Mat hsv;
    cvtColor(image, hsv, CV_BGR2HSV);

    for_each_pixel(hsv, [&inc](uchar * const pixel, int ) {
        if (pixel[1] <= 255-inc)
            pixel[1] += inc;
        else
            pixel[1] = 255;
    });

    cvtColor(hsv, image, CV_HSV2BGR);
}

void for_each_pixel(cv::Mat &image, std::function fn)
{
    int rows     = image.rows;
    int cols     = image.cols;
    int channels = image.channels();

    if (image.isContinuous())
    {
        cols = cols * rows;
        rows = 1;
    }

    for (int j=0; j<rows; ++j)
    {
        auto pixel = image.ptr(j);
        for (int i=0; i<cols; ++i, pixel += channels)
            fn(pixel, channels);
    }
}
*/

//#include <stdio.h>
//#include <cv.h>
//#include <highgui.h>
//#include <opencv2/highgui/highgui.hpp>
//using namespace cv;

//int main( int argc, char **argv ){
//    int key = 0, depth;
//    CvSize size;
//    Mat img = imread("/home/xdien/Pictures/notphotoshop.jpg");

//    /* Create a hsv image with 3 channels and hue, sat e val with 1 channel.
//       All with the same size */
//        Mat sat;
//        Mat hsv;

//    /* Convert from Red-Green-Blue to Hue-Saturation-Value */

//    cvtColor( img, hsv, CV_BGR2HSV );

//    for (int i=0; i < hsv.rows; i++)
//    {
//          for(int j=0; j < hsv.cols; j++)
//          {
//                // You need to check this, but I think index 1 is for saturation, but it might be 0 or 2
//                int idx = 0; //thay doi gi tri 0-2
//                hsv.at<cv::Vec3b>(i,j)[idx] += 25
//                        ;

//                // or:
//                hsv.at<cv::Vec3b>(i,j)[idx] += 20;// adds_constant_value;
//          }
//    }

//    cvtColor(hsv, sat, CV_HSV2BGR);
//    /* Split hue, saturation and value of hsv on them */
//    //cvSplit(hsv, hue, sat, val, 0);

//    /* Create windows, display them, wait for a key */
//    namedWindow( "Sources", 1 );
//    imshow( "Source",  sat);
//    namedWindow( "Source", 2 );
//    imshow( "ogin",  img);
//    cvWaitKey(0);

//    /* Free memory and get out */
//    return 0;
//}


//#include "opencv2/objdetect/objdetect.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"

//#include <iostream>
//#include <stdio.h>

//using namespace std;
//using namespace cv;

//double min_face_size=20;
//double max_face_size=200;
//Mat mask;

//Mat detectFace(Mat src);
//Mat putMask(Mat src,Point center,Size face_size);

//int main( )
//{
//    VideoCapture cap(0);
//    namedWindow( "window1", 1 );
//    mask = imread("/home/xdien/Pictures/ky-hieu-tay.jpg");

//    while(1)
//    {
//        Mat frame;
//        cap >> frame;
//        //frame=detectFace(frame);
//        putMask(frame,Point(100,100),Size(40,70));
//        imshow( "window1", frame );
//        // Press 'c' to escape
//        if(waitKey(1) == 'c') break;
//    }

//    waitKey(0);
//    return 0;
//}

//Mat detectFace(Mat image)
//{
//    // Load Face cascade (.xml file)
//    CascadeClassifier face_cascade( "C:/OpenCV243/data/Haarcascades/haarcascade_frontalface_alt2.xml" );

//    // Detect faces
//    std::vector<Rect> faces;

//    face_cascade.detectMultiScale( image, faces, 1.2, 2, 0|CV_HAAR_SCALE_IMAGE, Size(min_face_size, min_face_size),Size(max_face_size, max_face_size) );

//    // Draw circles on the detected faces
//    for( int i = 0; i < faces.size(); i++ )
//    {   // Lets only track the first face, i.e. face[0]
//        min_face_size = faces[0].width*0.7;
//        max_face_size = faces[0].width*1.5;
//        Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
//        image=putMask(image,center,Size( faces[i].width, faces[i].height));
//    }
//    return image;
//}

//Mat putMask(Mat src,Point center,Size face_size)
//{
//    Mat mask1,src1;
//    resize(mask,mask1,face_size);

//    // ROI selection
//     Rect roi(center.x - face_size.width/2, center.y - face_size.width/2, face_size.width, face_size.width);
//    src(roi).copyTo(src1);

//    // to make the white region transparent
//    Mat mask2,m,m1;
//    cvtColor(mask1,mask2,CV_BGR2GRAY);
//    threshold(mask2,mask2,230,255,CV_THRESH_BINARY_INV);

//    vector<Mat> maskChannels(3),result_mask(3);
//    split(mask1, maskChannels);
//    bitwise_and(maskChannels[0],mask2,result_mask[0]);
//    bitwise_and(maskChannels[1],mask2,result_mask[1]);
//    bitwise_and(maskChannels[2],mask2,result_mask[2]);
//    merge(result_mask,m );         //    imshow("m",m);

//    mask2 = 255 - mask2;
//    vector<Mat> srcChannels(3);
//    split(src1, srcChannels);
//    bitwise_and(srcChannels[0],mask2,result_mask[0]);
//    bitwise_and(srcChannels[1],mask2,result_mask[1]);
//    bitwise_and(srcChannels[2],mask2,result_mask[2]);
//    merge(result_mask,m1 );        //    imshow("m1",m1);

//    addWeighted(m,1,m1,1,0,m1);    //    imshow("m2",m1);

//    m1.copyTo(src(roi));

//    return src;
//}
/*----------------------------------------------------------------------*/
//#include <cv.h>
//#include <highgui.h>
//#include <iostream>

//using namespace cv;

//int main( int argc, char** argv )
//{
// double alpha = 0.5; double beta; double input;

// Mat src1, src2, dst;

// /// Ask the user enter alpha
// std::cout<<" Simple Linear Blender "<<std::endl;
// std::cout<<"-----------------------"<<std::endl;
// std::cout<<"* Enter alpha [0-1]: ";
// std::cin>>input;

// /// We use the alpha provided by the user if it is between 0 and 1
// if( input >= 0.0 && input <= 1.0 )
//   { alpha = input; }

// /// Read image ( same size, same type )
// src1 = imread("/home/xdien/Pictures/Webcam/2014-10-16-090412.jpg");
// src2 = imread("/home/xdien/Pictures/Webcam/2014-04-01-184600.jpg");

// if( !src1.data ) { printf("Error loading src1 \n"); return -1; }
// if( !src2.data ) { printf("Error loading src2 \n"); return -1; }

// /// Create Windows
// namedWindow("Linear Blend", 1);

// beta = ( 1.0 - alpha );
// addWeighted( src1, alpha, src2, beta, 0.0, dst);

// imshow( "Linear Blend", dst );

// waitKey(0);
// return 0;
//}
/*-------------------------------------------------------------------------------------*/
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include "stdio.h"

//#define HUEMAX 179
//#define SATMAX 255
//#define VALMAX 255

//using namespace std;
//using namespace cv;

//Mat HSV;
//int H =170;
//int S=200;
//int V =200;
//int R=0;
//int G=0;
//int B=0;

//int MAX_H=179;
//int MAX_S=255;
//int MAX_V=255;
//int mouse_x=0;
//int mouse_y=0;
//char window_name[20] = "HSV Color Plot";

////Global variable for hsv color wheel plot
//int max_hue_range=179;
//int max_step=3; //nuber of pixel for each hue color
//int wheel_width=max_hue_range*max_step;
//int wheel_hight=50;
//int wheel_x=50; //x-position of wheel
//int wheel_y=5;//y-position of wheel

////Global variable plot for satuarion-value plot
//int S_V_Width=MAX_S;
//int S_V_Height=MAX_S;
//int S_V_x=10;
//int S_V_y=wheel_y+wheel_hight+20;

////Global variable for HSV ploat
//int HSV_Width=150;
//int HSV_Height=150;
//int HSV_x=S_V_x+S_V_Width+30;
//int HSV_y=S_V_y+50;


//void onTrackbar_changed(int, void*);
//static void onMouse( int event, int x, int y, int, void* );
//void drawPointers(void);

//int main()
//{

//HSV.create(390,640,CV_8UC3); //Mat to store clock image
//HSV.setTo(Scalar(200,0,200));

//namedWindow(window_name);
//createTrackbar( "Hue",window_name, &H, HUEMAX, onTrackbar_changed );
//createTrackbar( "Saturation",window_name, &S, SATMAX,onTrackbar_changed );
//createTrackbar( "Value",window_name, &V, VALMAX,onTrackbar_changed);
//onTrackbar_changed(0,0); //initialoze window

//setMouseCallback( window_name, onMouse, 0 );
// while(true)
//  {
//    int c;
//    c = waitKey( 20 );
//    if( (char)c == 27 )
//      { break; }
//   }

//    return 0;
//}

//void onTrackbar_changed(int, void*){

////Plot color wheel.
//int hue_range=0;
//int step=1;
//for(int i=wheel_y;i<wheel_hight+wheel_y;i++){
//    hue_range=0;
//    for(int j=wheel_x;j<wheel_width+wheel_x;j++){
//   if(hue_range>=max_hue_range) hue_range=0;
//       if(step++==max_step){
//           hue_range++;
//           step=1;
//       }
//        Vec3b pix;
//        pix.val[0]=hue_range;
//        pix.val[1]=255;
//        pix.val[2]=255;


//     HSV.at<Vec3b>(i,j)=pix;

//    }

//}


////Plot for saturation and value
//int sat_range=0;
//int value_range=255;
//for(int i=S_V_y;i<S_V_Height+S_V_y;i++){
//    value_range--;
//    sat_range=0;
//for(int j=S_V_x;j<S_V_Width+S_V_x;j++){
//        Vec3b pix;
//        pix.val[0]=H;
//        pix.val[1]=sat_range++;
//        pix.val[2]=value_range;
//     HSV.at<Vec3b>(i,j)=pix;

//    }

//}

////Ploat for HSV
//Mat roi1(HSV,Rect(HSV_x,HSV_y,HSV_Width,HSV_Height));
//roi1=Scalar(H,S,V);
//drawPointers();

//Mat RGB;
//cvtColor(HSV, RGB,CV_HSV2BGR);

//imshow(window_name,RGB);
//imwrite("hsv.jpg",RGB);

//}

//static void onMouse( int event, int x, int y, int f, void* ){
//if(f&CV_EVENT_FLAG_LBUTTON){
//        mouse_x=x;
//        mouse_y=y;
//    if(((wheel_x<=x)&&(x<=wheel_x+wheel_width))&&((wheel_y<=y)&&(y<=wheel_y+wheel_hight))){
//        H=(x-wheel_x)/ max_step;
//        cvSetTrackbarPos("Hue", window_name, H);
//        }
//    else if(((S_V_x<=x)&&(x<=S_V_x+S_V_Width))&&((S_V_y<=y)&&(y<=S_V_y+S_V_Height))){

//        S=x-S_V_x;
//        y=y-S_V_y;
//        V=255-y;

//        cvSetTrackbarPos("Saturation", window_name, S);
//        cvSetTrackbarPos("Value", window_name, V);


//        }

//}

//}

//void drawPointers(){
//   // Point p(S_V_x+S,S_V_y+(255-V));
//    Point p(S,255-V);



//    int index=10;
//    Point p1,p2;
//    p1.x=p.x-index;
//    p1.y=p.y;
//    p2.x=p.x+index;
//    p2.y=p.y;

//    Mat roi1(HSV,Rect(S_V_x,S_V_y,S_V_Width,S_V_Height));
//    line(roi1, p1, p2,Scalar(255,255,255),1,CV_AA,0);
//    p1.x=p.x;
//    p1.y=p.y-index;
//    p2.x=p.x;
//    p2.y=p.y+index;
//    line(roi1, p1, p2,Scalar(255,255,255),1,CV_AA,0);

//    int x_index=wheel_x+H*max_step;
//    if(x_index>=wheel_x+wheel_width) x_index=wheel_x+wheel_width-2;
//    if(x_index<=wheel_x) x_index=wheel_x+2;

//    p1.x=x_index;
//    p1.y=wheel_y+1;
//    p2.x=x_index;
//    p2.y=wheel_y+20;
//    line(HSV, p1, p2,Scalar(255,255,255),2,CV_AA,0);

//    Mat RGB(1,1,CV_8UC3);
//    Mat temp;
//    RGB=Scalar(H,S,V);
//    cvtColor(RGB, temp,CV_HSV2BGR);
//    Vec3b rgb=temp.at<Vec3b>(0,0);
//    B=rgb.val[0];
//    G=rgb.val[1];
//    R=rgb.val[2];

//    Mat roi2(HSV,Rect(450,130,175,175));
//    roi2=Scalar(200,0,200);

//    char name[30];
//    sprintf(name,"R=%d",R);
//    putText(HSV,name, Point(460,155) , FONT_HERSHEY_SIMPLEX, .7, Scalar(5,255,255), 2,8,false );

//    sprintf(name,"G=%d",G);
//    putText(HSV,name, Point(460,180) , FONT_HERSHEY_SIMPLEX, .7, Scalar(5,255,255), 2,8,false );

//    sprintf(name,"B=%d",B);
//    putText(HSV,name, Point(460,205) , FONT_HERSHEY_SIMPLEX, .7, Scalar(5,255,255), 2,8,false );


//    sprintf(name,"H=%d",H);
//    putText(HSV,name, Point(545,155) , FONT_HERSHEY_SIMPLEX, .7, Scalar(5,255,255), 2,8,false );

//    sprintf(name,"S=%d",S);
//    putText(HSV,name, Point(545,180) , FONT_HERSHEY_SIMPLEX, .7, Scalar(5,255,255), 2,8,false );

//    sprintf(name,"V=%d",V);
//    putText(HSV,name, Point(545,205) , FONT_HERSHEY_SIMPLEX, .7, Scalar(5,255,255), 2,8,false );


//}
/*-----------------------------------------------------------------------*/
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
using namespace cv;
using namespace std;

int H_MIN = 0;
int H_MAX = 256;
int S_MIN = 0;
int S_MAX = 256;
int V_MIN = 0;
int V_MAX = 256;const string windowName = "Original Image";
const string windowName1 = "HSV Image";
const string windowName2 = "Thresholded Image";
const string windowName3 = "After Morphological Operations";
const string trackbarWindowName = "Trackbars";
void on_trackbar( int, void* )
{//This function gets called whenever a
    // trackbar position is changed
}

void overlayImage(const cv::Mat &background, const cv::Mat &foreground,
  cv::Mat &output, cv::Point2i location);
void createTrackbars(){
    //create window for trackbars
    namedWindow(trackbarWindowName,0);
    //create memory to store trackbar name on window
    char TrackbarName[50];
    sprintf( TrackbarName, "H_MIN", H_MIN);
    sprintf( TrackbarName, "H_MAX", H_MAX);
    sprintf( TrackbarName, "S_MIN", S_MIN);
    sprintf( TrackbarName, "S_MAX", S_MAX);
    sprintf( TrackbarName, "V_MIN", V_MIN);
    sprintf( TrackbarName, "V_MAX", V_MAX);
    //create trackbars and insert them into window
    //3 parameters are: the address of the variable that is changing when the trackbar is moved(eg.H_LOW),
    //the max value the trackbar can move (eg. H_HIGH),
    //and the function that is called whenever the trackbar is moved(eg. on_trackbar)
    //                                  ---->    ---->     ---->
    createTrackbar( "H_MIN", trackbarWindowName, &H_MIN, H_MAX, on_trackbar );
    createTrackbar( "H_MAX", trackbarWindowName, &H_MAX, H_MAX, on_trackbar );
    createTrackbar( "S_MIN", trackbarWindowName, &S_MIN, S_MAX, on_trackbar );
    createTrackbar( "S_MAX", trackbarWindowName, &S_MAX, S_MAX, on_trackbar );
    createTrackbar( "V_MIN", trackbarWindowName, &V_MIN, V_MAX, on_trackbar );
    createTrackbar( "V_MAX", trackbarWindowName, &V_MAX, V_MAX, on_trackbar );


}
void setLabel(Mat&,  string , Point );
void setLabel(Mat& im,  string label, Point ors)
{
    int fontface = cv::FONT_HERSHEY_SIMPLEX;
    double scale = 0.4;
    int thickness = 1;
    int baseline = 0;

    cv::Size text = cv::getTextSize(label, fontface, scale, thickness, &baseline);
    cv::rectangle(im, ors + Point(0, baseline), ors + Point(text.width, -text.height), CV_RGB(244,0,0), CV_AA);
    cv::putText(im, label, ors, fontface, scale, CV_RGB(255,255,255), thickness, 8);
}

char* source_window = "Source image";
char* warp_window = "Warp";
char* warp_rotate_window = "Warp + Rotate";
int main()
{
    Mat whole_image= imread("/home/xdien/Pictures/Webcam/2014-10-16-090412.jpg",-1);
    //Mat img = imread("/home/xdien/Pictures/frameO.png");

    createTrackbars();
//    cv::namedWindow("result");
//       whole_image.convertTo(whole_image,CV_32FC3,1.0/255.0);
//       cv::resize(whole_image,whole_image,img.size());
//       img.convertTo(img,CV_32FC3,1.0/255.0);

//       Mat bg=Mat(img.size(),CV_32FC3);
//       bg=Scalar(1.0,1.0,1.0);

//       // Prepare mask
//       Mat mask;
//       Mat img_gray;
//       cv::cvtColor(img,img_gray,cv::COLOR_BGR2GRAY);
//       img_gray.convertTo(mask,CV_32FC1);
//       threshold(1.0-mask,mask,0.9,1.0,cv::THRESH_BINARY_INV);

//       //cv::GaussianBlur(mask,mask,Size(21,21),11.0);
//       Mat res;

//       vector<Mat> ch_img(3);
//       vector<Mat> ch_bg(3);
//       cv::split(whole_image,ch_img);
//       cv::split(bg,ch_bg);
//       ch_img[0]=ch_img[0].mul(mask)+ch_bg[0].mul(1.0-mask);
//       ch_img[1]=ch_img[1].mul(mask)+ch_bg[1].mul(1.0-mask);
//       ch_img[2]=ch_img[2].mul(mask)+ch_bg[2].mul(1.0-mask);
//       cv::merge(ch_img,res);
//       cv::merge(ch_bg,bg);

//       imshow("result",res);
//       imshow("Mask",mask);
//       cv::waitKey(0);
//       cv::destroyAllWindows();
    /*resize(frame,frame,src.size());
    src.convertTo(src,CV_32FC4,1.0/255.0);
    frame.convertTo(frame, CV_32FC3,1.0/255.0);
    vector<Mat> ch;
    split(src,ch);
    Mat mask= ch[3].clone();
    ch.resize(3);
    Mat I1,I2,result;

       multiply(mask,ch[0],ch[0]);
       multiply(mask,ch[1],ch[1]);
       multiply(mask,ch[2],ch[2]);
       merge(ch,I1);

       vector<Mat> ch2(3);
       split(frame,ch2);
       multiply(1.0-mask,ch2[0],ch2[0]);
       multiply(1.0-mask,ch2[1],ch2[1]);
       multiply(1.0-mask,ch2[2],ch2[2]);
       merge(ch2,I2);

       result=I1+I2;
       imshow("Image",result);
       imshow("Mask",mask);
        waitKey(0);


    //cvtColor(src,thershold,CV_THRESH_BINARY);
    //cvtColor(src,HSV,CV_RGB2HSV);*/
    //res = whole_image.clone();

//    while(1){


//        inRange(hsv, cv::Scalar(H_MIN, S_MIN, V_MIN), cv::Scalar(H_MAX, S_MAX, V_MAX),thershold);

//        //delay 30ms so that screen can refresh.
//        //image will not appear without this waitKey() command
//        overlayImage(whole_image,img,thershold,Point2i(100,33));
//        imshow("thershold",thershold);

//        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
//        {
//            cout << "esc key is pressed by user" << endl;
//            break;
//        }
//    }
    //Mat imgOriginal = imread( "/home/xdien/Pictures/thiennhien.jpg");
    cv::Mat image = cv::imread("/home/xdien/Pictures/thiennhien.jpg");
    /// Read image given by user
    Mat new_image = Mat::zeros( image.size(), image.type() );

    double alpha; /**< Simple contrast control */
    int beta;  /**< Simple brightness control */
    /// Initialize values
    std::cout<<" Basic Linear Transforms "<<std::endl;
    std::cout<<"-------------------------"<<std::endl;
    std::cout<<"* Enter the alpha value [1.0-3.0]: ";std::cin>>alpha;
    std::cout<<"* Enter the beta value [0-100]: "; std::cin>>beta;

    /// Do the operation new_image(i,j) = alpha*image(i,j) + beta
    for( int y = 0; y < image.rows; y++ )
    { for( int x = 0; x < image.cols; x++ )
        { for( int c = 0; c < 3; c++ )
            {
                new_image.at<Vec3b>(y,x)[c] =
                        saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
            }
        }
    }

    /// Create Windows
    namedWindow("Original Image", 1);
    namedWindow("New Image", 1);

    /// Show stuff
    imshow("Original Image", image);
    imshow("New Image", new_image);

    /// Wait until user press some key
    waitKey();
    return 0;
}



