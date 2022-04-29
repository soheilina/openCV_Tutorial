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
 * @param vMin Value min value
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

/** @brief It gets intut from user to know wihch function should be run. If the input is invalid, the user has to try again.
 *  @param intput: the enterd input by user
 *  @param minVal: minimum value of range
 *  @param maxVal: maximum value of range
 */
int getInputFromUser(int input, int minVal, int maxVal){
    if(input>=minVal || input<=maxVal){
        return input;
    } else {
        std::cout << "You entered an invalid value. Please try again!" << std::endl;
        std::cin >> input;
        return getInputFromUser(input, minVal, maxVal);
    }
}

/** @brief Finds cotoures of objects in a dilated image and stores them in a 2D vector of points. Then print number of found objects out.
    @param imgDil a dilated image created from a canny image
    @param contoures an empty 2D vector of points to store contoures that are found
*/
void getContoures(cv::Mat& imgDil, std::vector<std::vector<cv::Point>>& contoures){
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(imgDil, contoures, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
}

}
#endif