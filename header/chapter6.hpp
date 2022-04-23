#include "pch.hpp"
#include "utils.hpp"


void chapter6(){
    std::string path{"../resource/car.jpeg"};
    cv::Mat img = cv::imread(path);
    // Creat a mask with HSV (i.e. Hue, Saturation, Value)
    cv::Mat imgMask, imgHSV;
    cv::cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);

    int hMin{0}, sMin{0}, vMin{0};
    int hMax{179}, sMax{255}, vMax{255};
    utilities::createTrackbars(hMin, hMax, sMin, sMax, vMin, vMax);

    // while-loop with waitKey(1) is requiered for the track-bar
    while(true){
        cv::Scalar lower(hMin, sMin, vMin);
        cv::Scalar upper(hMax, sMax, vMax);
        cv::inRange(imgHSV, lower, upper, imgMask);

        cv::imshow("Image", img);
        cv::imshow("Mask", imgMask);
        cv::imshow("HSV", imgHSV);
        cv::waitKey(1);
    }

}