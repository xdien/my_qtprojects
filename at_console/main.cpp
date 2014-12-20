/****************************************************************************
 *   Copyright 2014 Unknown <bdienw@gmail.com>								*
 * 																			*
 * This program is free software; you can redistribute it and/or modify		*
 * it under the terms of the GNU General Public License as published by		*
 * the Free Software Foundation; either version 2 of the License, or		*
 * (at your option) any later version.										*
 * 																			*
 * This program is distributed in the hope that it will be useful,			*
 * but WITHOUT ANY WARRANTY; without even the implied warranty of			*
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			*
 * GNU General Public License for more details.								*
 * 																			*
 * You should have received a copy of the GNU General Public License		*
 * along with this program; if not, write to the Free Software				*
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,				*
 * MA 02110-1301, USA.                  		                            *
 *                                                                    		*
 ***************************************************************************/
#include "opencv/highgui.h"
#include <QCoreApplication>
#include "stdio.h"
#include "opencv/cv.h"
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
    /*QCoreApplication a(argc, argv);
    serial.setPortName("/dev/ttyUSB3");
    if(serial.open(QSerialPort::ReadWrite))
    {
        printf("Mo cong ttyUSB3 thanh cong!\n");
    }
    else
    {
        printf("Mo cong ttyUSB3 khong thannh cong\n");
        exit(1);
    }
    return a.exec();*/
    if(argc != 2)
    {
        printf("usage: DisplayImage.out <ImgPath>\n");
        return -1;
    }
    Mat image;
    image = imread(argv[1],1);
    if(!image.data)
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image",CV_WINDOW_AUTOSIZE);
    imshow("Display Image",image);
    waitKey(0);
    return 0;
}
