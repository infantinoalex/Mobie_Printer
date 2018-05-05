#ifndef LINEDRAWINGCONTROLLER_HPP
#define LINEDRAWINGCONTROLLER_HPP

#include "../Image/Image.hpp"
#include "../Image/ImageConverter.hpp"
#include "../PrinterHead/PrinterHead.hpp"

#include <stdexcept>
#include <iostream>
#include <kipr/botball.h>

/*
 * Main driver for the program. Contains the main methods that will be called
 * from main.cpp to controll the various parts of the printer.
 * 
 * TODO: Determine how to do constructor injection properly so that classes can be instantiated in
 *       main.cpp and passed via constructor.
 */
class LineDrawingController : public Controller
{
    public:
        LineDrawingController();

        // Based upon the Image object, sends control over to the motors to draw the image
        // on paper. This will use a more appropriate line drawing algorithm that should be able to
        // draw straight lines, curved lines, etc... properly
        void DrawImage();
};

#endif
