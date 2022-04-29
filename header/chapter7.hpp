#include "pch.hpp"

/** @brief Draws contoures, a polygon for each object conecting its corners, and bounding boxes.
           The type of each object is recognized based on number of its corners stored in cornerPolygon.
           The type of each object is shown besides each bounding box.
    @param img an image
    @param contoures a 2D vector of points. Found contoures have been stored in it.
*/
void detectObjects(cv::Mat img, std::vector<std::vector<cv::Point>>& contoures){
    uint8_t numberOfDetectedObjects = contoures.size();
    std::vector<std::vector<cv::Point>> cornerPolygon(numberOfDetectedObjects);
    std::vector<cv::Rect> boundingRectangule(numberOfDetectedObjects);
    for(int i=0; i<numberOfDetectedObjects; i++){
        int shapeArea = cv::contourArea(contoures[i]);

        std::cout << "The contoure of image " << i+1 << " at points " << contoures[i][0] << " and " << contoures[i][1] <<
                    " has an area of " << shapeArea << std::endl;
        
        // Filters outliers i.e. small redundant objects. So contoures around only desired objects are drawn.
        if(shapeArea>1500){
            cv::drawContours(img, contoures, i , cv::Scalar(255,0,255), 2);
            
            // Draw a poly around each shape
            float peri = cv::arcLength(contoures[i], true);
            cv::approxPolyDP(contoures[i], cornerPolygon[i], 0.02*peri, true);
            cv::drawContours(img, cornerPolygon, i , cv::Scalar(0,0,0), 2);

            // Draw bounding box areound each shape. Note: You can pass either contoures or cornerPolygon.
            boundingRectangule[i] = cv::boundingRect(contoures[i]);
            cv::rectangle(img, boundingRectangule[i].tl(), boundingRectangule[i].br(), cv::Scalar(0, 255, 0), 2);

            // Detect every object based on its corners
            std::string objectType;
            uint8_t numberOfCorners = static_cast<uint8_t>(cornerPolygon[i].size());
            if(numberOfCorners==3){
                objectType="Triangle";
            }
            else if(numberOfCorners==4){
                float aspectRatio = static_cast<float>(boundingRectangule[i].height)/boundingRectangule[i].width;
                std::cout << "aspectRatio: " << aspectRatio << std::endl;
                // Note: As sqaures might not be perfect, aspect ratio isn't exactly 1.
                if(aspectRatio>= 0.9 && aspectRatio <=1.1)
                    objectType = "Square";
                else
                    objectType = "Rect";
            }
            else{
                objectType = "Circle";
            }
            cv::putText(img, objectType, boundingRectangule[i].tl(), cv::FONT_HERSHEY_DUPLEX, 0.5, cv::Scalar(0,0,0), 1);
        }
    }
}

void chapter7(){
    const std::string path{"../resource/shapes.png"};
    cv::Mat img{cv::imread(path)}, imgCanny, imgDil;

    // ---> Preprocessing: Finding countours to detect shapes later <---
    cv::Canny(img, imgCanny, 25, 75);
    // Since edges in Canny are thin there might be disconnection in the counter of an image. As remedy we dilate the canny:
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3));
    cv::dilate(imgCanny, imgDil, kernel);

    // ---> Get contoures <---
    // contoures is an Nx2 matrix. N is number of detected shapes. Every row has two points describing a contoure of a shape.
    std::vector<std::vector<cv::Point>> contoures;
    utilities::getContoures(imgDil, contoures);
    std::cout << "The number of detected shapes is: " << contoures.size() << std::endl;

    // ---> Detect objects <---
    detectObjects(img, contoures);

    // Add info to the image
    const std::string info{"Info: contoures in purple. Polygon of corners in black. Bounding boxes in green"};
    cv::putText(img, info, cv::Point(0, 30), cv::FONT_ITALIC, 0.55, cv::Scalar(0,69,255), 2);
    
    cv::imshow("Image", img);
    //cv::imshow("Image Canny", imgCanny);
    //cv::imshow("Image Dil", imgDil);
    cv::waitKey(0);
}