#ifndef CONTROLLER_H
#define CONTROLLER_H

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
class Controller
{
    public:
        Controller();
	~Controller();

        // Method that polls the port connected to the bumper.
        // Returns
        //      True - If the bumper was hit
        //      False - otherwise
        bool IsStartBumperHit();

        // Using the ImageConverter, determines what the camera is seeing
        // and converts the data into an Image object.
        void GrabAndConvertImageData();

        // Based upon the Image object, sends control over to the motors to draw the image
        // on paper.
        void DrawImage();

    private:
        // Representation of the image seen internally
        Image _image;

        // Used to convert what the camera sees to an image
        ImageConverter _imageConverter;

        // The printer head object which controls the motors/pen for drawing
        PrinterHead _printerHead;

        // The port the bumper is using
        int _bumperPort;
};

#endif
