#include "../includes/LineDrawingController.hpp"

#include <iostream>

#define BUMPER_PORT 0

// WIP and not complete. This was supposed to be a more sophisticated version of the Controller that
// will use some algorithm to actually follow paths and therefore produce a better image.
LineDrawingController::LineDrawingController()
{
    this->_printerHead = PrinterHead();

    this->_bumperPort = BUMPER_PORT;

    std::map<Colors, Image> colorsMap = CreateShapeImages();
    this->_imageConverter = ColorImageConverter(colorsMap);
}

void LineDrawingController::DrawImage()
{
    // Might have to use different data structure than a vector to represent the image or may need to further
    // process the array values in the image better here.
}