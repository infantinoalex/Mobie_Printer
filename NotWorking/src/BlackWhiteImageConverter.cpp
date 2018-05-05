#include "../includes/EdgeImageConverter.hpp"

#include <stdexcept> 
#include <kipr/botball.h>

BlackWhiteImageConverter::BlackWhiteImageConverter()
{
    this->_maxCameraHeight = 100;
    this->_maxCameraWidth = 60;

    this->_whiteCameraChannel = 5;
    this->_biggestObjectIndex = 0;
}

// This is a POC and not working. Was a WIP
Image BlackWhiteImageConverter::GrabAndConvertImage()
{
    // Opens camera and sets the max height and width to the possible max for the printer
    camera_open();

    set_camera_height(this->_maxCameraHeight);
    set_camera_width(this->_maxCameraWidth);

    msleep(100);
    while(!camera_update());

    // Could use get_object_bbox(channel, object) to grab the biggest white object
    // being seen by the camera, so now we know what pixels are relevant

    unsigned char * foundCameraFrame = get_camera_frame();

    // Using white, will find the biggest white object it can (which should be the piece of paper)
    // and will try to draw it
    rectangle objectRectangle = get_object_bbox(this->_whiteCameraChannel, this->_biggestObjectIndex);
    int objectArea = get_object_area(this->_whiteCameraChannel, this->_biggestObjectIndex);

    // Ensure that we actually got an object by looking at the object area
    int failedLoop = 0;
    while (objectArea == -1)
    {
        if (failedLoop > 2000)
        {
            throw std::runtime_error("Camera could not find the image in the alloted time");
        }

        objectRectangle = get_object_bbox(this->_whiteCameraChannel, this->_biggestObjectIndex);
        objectArea = get_object_area(this->_whiteCameraChannel, this->_biggestObjectIndex);
        failedLoop++;
    }

    // Loop through based upon the rectangles width and height
    int heightLoop;
    int widthLoop;
    int resultingArray[objectRectangle.height * objectRectangle.width] = {0};
    for (heightLoop = 0; heightLoop < objectRectangle.height; ++heightLoop)
    {
        for (widthLoop = 0; widthLoop < objectRectangle.width; ++widthLoop)
        {
            point2 pointToFind;

            // Assuming the ulx and uly are the origin points for the rectangle
            pointToFind.x = widthLoop + objectRectangle.ulx;
            pointToFind.y = heightLoop + objectRectangle.uly;

            pixel pixelValue = get_camera_pixel(pointToFind);

            // If it is black, then we put a 1 in the value in the array, else we ignore it
            if (pixelValue.r < 105 && pixel.g < 105 && pixel.b < 105)
            {
                resultingArray[objectRectangle.height * heightLoop + widthLoop] = 1;
            }
        }
    }

    // Create the image and return it
    Image createdImage = Image();
    std::vector<int> resultingVector = std::vector<int>(resultingArray, resultingArray + sizeof(resultingArray) / sizeof(resultingArray[0]));
    createdImage.SetImage(resultingVector, objectRectangle.width, objectRectangle.height);
    return createdImage;
}