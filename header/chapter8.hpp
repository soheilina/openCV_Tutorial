#include "pch.hpp"

void chapter8(){
    const std::string path{"../resource/people.jpeg"};
    cv::Mat img{cv::imread(path)};

    cv::CascadeClassifier faceCascade;
    try{
        // NOTE: It detects frontal faces
        faceCascade.load("../resource/haarcascade_frontalface_default.xml");
        
        if(faceCascade.empty()){
            throw "ERORR:  ---> XML could not be loaded! <---";
        }
    } catch(const char* msg) {
        std::cerr << msg << std::endl;
    }

    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 10);

    for(uint8_t i=0; i<faces.size(); i++){
       cv::rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(255, 0, 255), 2);
    }

    cv::imshow("Image", img);
    cv::waitKey(0);
}