#include "pch.hpp"

void showImage(const std::string& path){
    const std::string imagePath = path + "golshifteh_3" + ".jpeg";
    cv::Mat img{cv::imread(imagePath)};
    cv::imshow("Image", img);
    cv::waitKey(0);
}

void showVideo(const std::string& path){
    const std::string framePath = path + "snow" + ".mp4";
    cv::VideoCapture cap{framePath};
    cv::Mat frame;
    
    while(true){
        cap.read(frame);
        cv::imshow("frame", frame);
        cv::waitKey(1);//by increaseing the input the video gets slower
    }
}

void showWebcam(){
    const uint8_t cameraID{0};
    cv::VideoCapture cap{cameraID};
    cv::Mat frame;
    
    while(true){
        cap.read(frame);
        cv::imshow("frame", frame);
        cv::waitKey(1);
    }
}

void chapter1(){
    const std::string path = "../resource/";
    int input{0};
    std::cout << "Please enter "
              << "(1) to show an image, "
              << "(2) to show a video, "
              << "(3) to open the webcam" << std::endl;
    std::cin >> input;
    switch (utilities::getInputFromUser(input, 1, 3)){
        case 1:{
            showImage(path);
            break;
        }
        case 2:{
            showVideo(path);
            break;
        }
        case 3:{
            showWebcam();
            break;
        }
    
    default:{
        std::cout << "Your input is out of range!" << std::endl;
        break;
    }
    }
}