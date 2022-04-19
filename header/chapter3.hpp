#include "pch.hpp"

void chapter3(){
    const std::string path = "../resource/";
    const std::string imagePath = path + "golshifteh_2" + ".jpeg";

    cv::Mat img{cv::imread(imagePath)}, resized_image1, resized_image2, cropped_image;
    auto [width, height] = img.size();
    std::cout << "The image size is: " << img.size() << std::endl;

    // resizing by sending absolute number
    cv::resize(img, resized_image1, cv::Size(width/2, height/2));
    // resizing by sending scaling ratio
    double scale_x{1.5};
    double scale_y{1.5};
    cv::resize(img, resized_image2, cv::Size(), scale_x, scale_y);

    // cropping
    int x{100};
    int y{100};
    width = 305;
    height = 550;
    cv::Rect regionOfInterest(x, y, width, height);
    cropped_image = img(regionOfInterest);

    // showing
    cv::imshow("Image", img);
    cv::imshow("Image_Resized_1", resized_image1);
    cv::imshow("Image_Resized_2", resized_image2);
    cv::imshow("Image_cropped", cropped_image);

    cv::waitKey(0);
}