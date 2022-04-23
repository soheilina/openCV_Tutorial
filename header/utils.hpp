namespace utilities{
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

}