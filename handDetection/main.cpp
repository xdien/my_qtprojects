#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    Mat mask;
    Mat img_gray;
    Mat res;
    namedWindow("result");
    Mat img=imread("/home/xdien/Pictures/Webcam/2014-10-16-085809.jpg");
    Mat whole_image=imread("/home/xdien/Pictures/Webcam/2014-10-16-085749.jpg");
    whole_image.convertTo(whole_image,CV_32FC3,1.0/255.0);
    resize(whole_image,whole_image,img.size());
    img.convertTo(img,CV_32FC3,1.0/255.0);

    Mat bg=Mat(img.size(),CV_32FC3);
    bg=Scalar(1.0,1.0,1.0);

    // Prepare mask
    cvtColor(img,img_gray,COLOR_BGR2GRAY);
    img_gray.convertTo(mask,CV_32FC1);
    threshold(1.0-mask,mask,0.9,1.0,THRESH_BINARY_INV);

    GaussianBlur(mask,mask,Size(21,21),11.0);

    vector<Mat> ch_img(3);
    vector<Mat> ch_bg(3);
    split(whole_image,ch_img);
    split(bg,ch_bg);
    ch_img[0]=ch_img[0].mul(mask)+ch_bg[0].mul(1.0-mask);
    ch_img[1]=ch_img[1].mul(mask)+ch_bg[1].mul(1.0-mask);
    ch_img[2]=ch_img[2].mul(mask)+ch_bg[2].mul(1.0-mask);
    merge(ch_img,res);

    imshow("result",res);
    waitKey(0);
    destroyAllWindows();
}
