#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace cv;
using namespace std;

double alpha; /**< Simple contrast control */
int beta;  /**< Simple brightness control */
int APHA_MIN = 1;
int APHA_MAX = 3;
int BETA_MIN = 1;
int BETA_MAX = 100;
int V_MIN = 0;
int V_MAX = 256;
int threshold_value = 0;
int threshold_type = 3;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;
const string trackbarWindowName = "Trackbars";
Mat src, src_gray, dst,histogram;
void on_trackbar( int, void* )
{//This function gets called whenever a
    // trackbar position is changed





}
void createTrackbar(){
    cv::namedWindow(trackbarWindowName,0);
    //create memory to store trackbar name on window
    char TrackbarName[50];
    sprintf( TrackbarName, "APHA_MIN", APHA_MIN);
    sprintf( TrackbarName, "APHA_MAX", APHA_MAX);
    sprintf( TrackbarName, "BETA_MIN", BETA_MIN);
    sprintf( TrackbarName, "BETA_MAX", BETA_MAX);
    sprintf( TrackbarName, "V_MIN", V_MIN);
    sprintf( TrackbarName, "V_MAX", V_MAX);
    //create trackbars and insert them into window
    //3 parameters are: the address of the variable that is changing when the trackbar is moved(eg.H_LOW),
    //the max value the trackbar can move (eg. H_HIGH),
    //and the function that is called whenever the trackbar is moved(eg. on_trackbar)
    //                                  ---->    ---->     ---->
    createTrackbar( "APHA", trackbarWindowName, &APHA_MIN, APHA_MAX, on_trackbar );
    //createTrackbar( "APHA_MAX", trackbarWindowName, &APHA_MAX, APHA_MAX, on_trackbar );
    createTrackbar( "BETA", trackbarWindowName, &BETA_MIN, BETA_MAX, on_trackbar );
    //createTrackbar( "BETA_MAX", trackbarWindowName, &BETA_MAX, BETA_MAX, on_trackbar );
    //createTrackbar( "V_MIN", trackbarWindowName, &V_MIN, V_MAX, on_trackbar );
    //createTrackbar( "V_MAX", trackbarWindowName, &V_MAX, V_MAX, on_trackbar );
    createTrackbar("Threshold value",trackbarWindowName,&threshold_value,max_value,on_trackbar);
    createTrackbar("Threshold type",trackbarWindowName,&threshold_type,max_type,on_trackbar);
}
void Threshold_Demo( int, void* )
{
  /* 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
   */

  threshold( src_gray, dst, threshold_value, max_BINARY_value,threshold_type );
}

int main( int argc, char** argv )
{
    VideoCapture cap(0);
 /// Read image given by user
 Mat image;

 Mat new_image;
 createTrackbar();
 /// Create Windows
 namedWindow("Original Image", 1);
 namedWindow("New Image", 1);
 /// Initialize values
 std::cout<<" Basic Linear Transforms "<<std::endl;
 std::cout<<"-------------------------"<<std::endl;
 //std::cout<<"* Enter the alpha value [1.0-3.0]: ";std::cin>>APHA_MIN;
 //std::cout<<"* Enter the a value [0-100]: "; std::cin>>BETA_MIN;
 vector<Mat> channels;
 Mat img_hist_equalized;
while(1)
{
    cap.read(image);
    new_image = Mat::zeros( image.size(), image.type() );
    /// Do the operation new_image(i,j) = alpha*image(i,j) + BETA_MIN
    for( int y = 0; y < image.rows; y++ )
    { for( int x = 0; x < image.cols; x++ )
        { for( int c = 0; c < 3; c++ )
            {
                new_image.at<Vec3b>(y,x)[c] =
                        saturate_cast<uchar>( APHA_MIN*( image.at<Vec3b>(y,x)[c] ) + BETA_MIN);
            }
        }
    }
    cvtColor( new_image, src_gray, CV_RGB2GRAY );
    threshold(src_gray, dst, threshold_value, max_BINARY_value,threshold_type );
    equalizeHist( src_gray, histogram);
    //can bang histogram
    cvtColor(new_image, img_hist_equalized, CV_BGR2YCrCb); //change the color image from BGR to YCrCb format

    split(img_hist_equalized,channels); //split the image into channels

    equalizeHist(channels[0], channels[0]); //equalize histogram on the 1st channel (Y)

    merge(channels,img_hist_equalized); //merge 3 channels including the modified 1st channel into one image

    cvtColor(img_hist_equalized, img_hist_equalized, CV_YCrCb2BGR); //change the color image from YCrCb to BGR format (to display image properly)


    /// Show stuff
    ///
    imshow("Original Image", image);
    imshow("New Image", new_image);
    imshow("Threshold & bri",dst);
    imshow("Histogram",img_hist_equalized);

    /// Wait until user press some key
    if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
    {
        std::cout << "esc key is pressed by user" << std::endl;
        break;
    }
}
return 0;

}
