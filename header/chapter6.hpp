#include "pch.hpp"

int hMin{0}, sMin{0}, vMin{0};
int hMax{179}, sMax{255}, vMax{255};

/* @brief: By means of a track-bar we can find min & max values for H, S, and V.
 * At the begining, the Mask Image is white. H, S, and V are achieved by sliding the bars and trying to keep the desired color white in the Mask Image.
 * Then we can set them to find the desired color.
*/
void createTrackbars(){
    cv::namedWindow("Trackbars");
    cv::createTrackbar("Hue Min", "Trackbars", &hMin, 179);
    cv::createTrackbar("Hue Max", "Trackbars", &hMax, 179);
    cv::createTrackbar("Saturation Min", "Trackbars", &sMin, 255);
    cv::createTrackbar("Saturation Max", "Trackbars", &sMax, 255);
    cv::createTrackbar("Value Min", "Trackbars", &vMin, 255);
    cv::createTrackbar("Value Max", "Trackbars", &vMax, 255);
}

void chapter6(){
    std::string path{"../resource/car.jpeg"};
    cv::Mat img = cv::imread(path);
    // Creat a mask with HSV (i.e. Hue, Saturation, Value)
    cv::Mat imgMask, imgHSV;
    cv::cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);

    createTrackbars();

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