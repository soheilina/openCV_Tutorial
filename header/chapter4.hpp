#include "pch.hpp"

void chapter4(){
    // make a blank image
    double height{512};
    double width{512};
    auto [blue, green, red] = std::tuple(255U, 255U, 255U);
    cv::Mat img(height, width, CV_8UC3 ,cv::Scalar(blue, green, red)), img2;

    // Add a circle to the image
    auto center = cv::Point(height/2, width/2);
    int radius = 156;
    auto color = cv::Scalar(0,0,255);
    int thickness{cv::FILLED};
    cv::circle(img, center, radius, color, thickness);

    // Add a rectangle to the image
    auto top_left_corner = cv::Point(130, 226);
    auto bottom_right_corner = cv::Point(382, 286);
    color = cv::Scalar(255, 255, 255);
    thickness = cv::FILLED;
    cv::rectangle(img, top_left_corner, bottom_right_corner, color, thickness); // see also cv::Rect in chapter3
    
    // Add a line
    auto start = cv::Point(130, 296);
    auto end = cv::Point(382, 296);
    color = cv::Scalar(0, 255, 0);
    thickness = 2;
    cv::line(img, start, end, color, thickness);

    // Add text
    std::string text{"This is a text!"};
    start = cv::Point(130, 260);
    color = cv::Scalar(255, 0, 0);
    double fontScale = 0.75;
    cv::putText(img, text, start, cv::FONT_HERSHEY_DUPLEX, fontScale, color, thickness);


    cv::imshow("Image", img);

    cv::waitKey(0);
}