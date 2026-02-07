// opencvExperiments.cpp : Defines the entry point for the application.
//

#include "opencvTemplateMain.h"
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;


#ifdef ENABLE_CONSOLE
int main()
#else
int WinMain()
#endif
{

    cv::Mat image;
    image = cv::imread("assets/crystal.jpg", cv::IMREAD_COLOR);

    if (!image.data)
    {
        printf("No image data \n");
        return -1;
    }
    cv::namedWindow("Display Image", cv::WINDOW_NORMAL);
    cv::Size windowSize{ 100, 100 };
    cv::resizeWindow("Display Image", windowSize);
    cv::imshow("Display Image", image);

    cv::waitKey(0);

	return 0;
}
