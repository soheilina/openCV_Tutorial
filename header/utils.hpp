#ifndef UTILS_HPP
#define UTILS_HPP
namespace utilities
{

 /** @brief By means of a track-bar we can find min & max values for H, S, and V.
 *         At the begining, the Mask Image is white. H, S, and V are achieved by sliding the bars and trying to keep the desired color white in the Mask Image.
 *         Then we can set them to find the desired color.
 * @param hMin Hue min value
 * @param hMax Hue max value
 * @param sMin Saturation min value
 * @param sMax Saturation max value
 * @param vMin Value max value
 * @param vMax Value max value
*/
void createTrackbars(int& hMin, int& hMax, int& sMin, int& sMax, int& vMin, int& vMax){
    cv::namedWindow("Trackbars");
    cv::createTrackbar("Hue Min", "Trackbars", &hMin, 179);
    cv::createTrackbar("Hue Max", "Trackbars", &hMax, 179);
    cv::createTrackbar("Saturation Min", "Trackbars", &sMin, 255);
    cv::createTrackbar("Saturation Max", "Trackbars", &sMax, 255);
    cv::createTrackbar("Value Min", "Trackbars", &vMin, 255);
    cv::createTrackbar("Value Max", "Trackbars", &vMax, 255);
}

/** @brief Finds min and max of HSV (i.e. Hue, Saturation, Value) values of an object in fornt of the webcam by means a trackbar.
 *         You need to adjust the trackbar so that the desired object remains white and all other objects turn to black.
 */
void findColorsFromWebcam(){
    const uint8_t cameraID{0};
    cv::Mat frame, frameMask, frameHSV;
    int hMin{0}, sMin{0}, vMin{0};
    int hMax{179}, sMax{255}, vMax{255};
    std::vector<int> HSV;

    utilities::createTrackbars(hMin, hMax, sMin, sMax, vMin, vMax);

    cv::VideoCapture cap{cameraID};

    while(true){
        cap.read(frame);
        // Creat a mask with HSV (i.e. Hue, Saturation, Value)
        cv::cvtColor(frame, frameHSV, cv::COLOR_BGR2HSV);

        cv::Scalar lower(hMin, sMin, vMin);
        cv::Scalar upper(hMax, sMax, vMax);
        cv::inRange(frameHSV, lower, upper, frameMask);

        cv::imshow("frame", frame);
        cv::imshow("frame Mask", frameMask);
        cv::waitKey(1);
        std::cout << hMin << " " << hMax << " " << sMin << " " << sMax << " " << vMin << " " << vMax << std::endl;
    }
}

}
#endif