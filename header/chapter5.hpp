#include "pch.hpp"

constexpr float width{250}, height{350};

void warper(cv::Point2f* src, cv::Point2f* dest, cv::Mat& originalImg, cv::Mat& warpedImg){
    cv::Mat matrix = cv::getPerspectiveTransform(src, dest);
    cv::warpPerspective(originalImg, warpedImg, matrix, cv::Point(width, height));
}

void markSelectedPoints(cv::Mat& originalImg, cv::Point2f* src){
    for(int i=0; i<4; i++){
        cv::circle(originalImg, src[i], 3, cv::Scalar(0, 0, 255), 3);
    }
}

void chapter5(){
    const std::string path{"../resource/cards.jpeg"};
    cv::Mat img{cv::imread(path)}, imgWrap_jack, imgWrap_spade7;

    // warping --> Jack <--
    cv::Point2f src[4] = {{69, 455}, {142, 408}, {123, 556}, {206, 498}};
    cv::Point2f dest[4] = {{0.0f, 0.0f}, {width, 0.0f}, {0.0f, height}, {width, height}};
    warper(src, dest, img, imgWrap_jack);
    // mark selected corner points
    markSelectedPoints(img, src);
    
    
    // warping --> Spade-7 <--
    src[0] = {167, 399};
    src[1] = {231, 360};
    src[2] = {232, 488};
    src[3] = {298, 442};
    warper(src, dest, img, imgWrap_spade7);
    // mark selected corner points
    markSelectedPoints(img, src);

    cv::imshow("Original image", img);
    cv::imshow("Warped image: Jack", imgWrap_jack);
    cv::imshow("Warped image: Spade7", imgWrap_spade7);
    cv::waitKey(0);
}