#include "../includes/Controller.hpp"
#include "Helper.cpp"
#include "../includes/ColorImageConverter.hpp"

#include <iostream>

#define BUMPER_PORT 0

Controller::Controller()
{
    this->_printerHead = PrinterHead();

    this->_bumperPort = BUMPER_PORT;

    std::map<Colors, Image> colorsMap = CreateShapeImages();
    this->_imageConverter = ColorImageConverter(colorsMap);
}

bool Controller::IsStartBumperHit()
{
    // Returns true if the bumper was hit
    if (digital(this->_bumperPort))
    {
        std::cout << "Bumper has been hit." << std::endl;
        return true;
    }

    return false;
}

void Controller::GrabAndConvertImageData()
{
    // Calls the image converter to poll the camera and convert it to an image object
    std::cout << "Grabbing and converting the image from the camera." << std::endl;
    this->_image = this->_imageConverter.GrabAndConvertImage();
}

void Controller::DrawImage()
{
    // Gets the width and height of the image for the loop
    int width = this->_image.GetImageWidth();
    int height = this->_image.GetImageHeight();

    std::cout << "Moving printer head home before printing begins." << std::endl;

    this->_printerHead.MovePrinterHeadHome();
    msleep(100);

    // If the height is even, we go left to right.
    // If the height is odd, we  go right to left
    // Algorithm:
    //      Grabs the value of the pixel (1 or 0) at the next location. 
    //      Lowers/Raises the printer head based on this value
    //      Moves to that location
    //  Exception:
    //      If the printer head cannot move to the location, the method will return
    //      false and the controller will throw an exception
    std::cout << "Printing out the pixels of the image." << std::endl;
    for (int heightLoop = 0; heightLoop < height; ++heightLoop)
    {
        if (heightLoop % 2 == 0)
        {
            for (int widthLoop = 0; widthLoop < width; ++widthLoop)
            {
                int pixelValue = this->_image.GetImagePixelAtIndex(widthLoop, heightLoop);
                if (pixelValue)
                {
                    this->_printerHead.LowerPrinter();
                }
                else
                {
                    this->_printerHead.RaisePrinter();
                }

                if (!this->_printerHead.TryMovePrinterHead(widthLoop + 1, heightLoop))
                {
                    throw std::runtime_error("Could not move printer head to location.");
                }
            }
        }
        else
        {
            for (int widthLoop = width - 1; widthLoop > -1; --widthLoop)
            {
                int pixelValue = this->_image.GetImagePixelAtIndex(widthLoop, heightLoop);
                if (pixelValue)
                {
                    this->_printerHead.LowerPrinter();
                }
                else
                {
                    this->_printerHead.RaisePrinter();
                }

                if (!this->_printerHead.TryMovePrinterHead(widthLoop + 1, heightLoop))
                {
                    throw std::runtime_error("Could not move printer head to location.");
                }
            }
        }
    }
}
