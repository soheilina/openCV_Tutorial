#include "pch.hpp"

#include "chapter1.hpp"
#include "chapter2.hpp"

using namespace cv;
using namespace std;
int main(){
    /*
    cv::Mat img(512,512,CV_8UC3, Scalar(255,0,255));
    imshow("Image", img);
    std::cout << "hi!" << std::endl;
    */
   /*string path="../resource/me.jpg";
   Mat img = imread(path);
   imshow("Image", img);
    waitKey(0);*/
    chapter2();
    return 0;
}