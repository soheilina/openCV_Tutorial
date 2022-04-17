#include "pch.hpp"

void chapter2(){
    const std::string path = "../resource/";
    const std::string imagePath = path + "golshifteh_1" + ".jpeg";
    cv::Mat img = cv::imread(imagePath);
    cv::Mat imgGray, imgBlur1, imgBlur2, imgCanny, imgDilate, imgErode;
    
    // converts to gray
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
    
    // blurs. cv::Size gets only odd inputs.
    cv::GaussianBlur(img, imgBlur1, cv::Size(7,1), 5, 0); //(7,1) blurs hotizontally
    cv::GaussianBlur(img, imgBlur2, cv::Size(1,7), 5, 0); //(1,7) blurs vertically
    
    // detects edges of image. By decreasing thresholds more edges are detected.
    double threshold1 = 25;
    double threshold2 = 75;
    cv::Canny(img, imgCanny, threshold1, threshold2);

    // Dilates (i.e. increase the thickness of edges) and erodes (i.e. decrease the thickness of edges). It works on normal image and also on canny image
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3));
    cv::dilate(imgCanny, imgDilate, kernel); // increases the thickness
    cv::erode(imgDilate, imgErode, kernel); // decreasing the thickness
    
    cv::imshow("original_image", img);
    cv::imshow("gray_Image", imgGray);
    cv::imshow("blured_image1", imgBlur1);
    cv::imshow("blured_image2", imgBlur2);
    cv::imshow("canny_image", imgCanny);
    cv::imshow("dialted_image", imgDilate);
    cv::imshow("eroded_image", imgErode);

    cv::waitKey(0);
}