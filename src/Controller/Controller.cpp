#include "Controller.hpp"
#include "../Exception/CustomExceptions.cpp"
#include "../Helper.cpp"
#include "../Image/ColorImageConverter.hpp"

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
    if (digital(this->_bumperPort))
    {
        std::cout << "Bumper has been hit." << std::endl;
        return true;
    }

    return false;
}

void Controller::GrabAndConvertImageData()
{
    std::cout << "Grabbing and converting the image from the camera." << std::endl;
    this->_image = this->_imageConverter.GrabAndConvertImage();
}

void Controller::DrawImage()
{
    int width = this->_image.GetImageWidth();
    int height = this->_image.GetImageHeight();

    std::cout << "Moving printer head home before printing begins." << std::endl;

    this->_printerHead.MovePrinterHeadHome();

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

                std::cout << "Drawing at location X: " << widthLoop << "\tY: " << heightLoop << std::endl;
                if (!this->_printerHead.TryMovePrinterHead(widthLoop, heightLoop))
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

                if (!this->_printerHead.TryMovePrinterHead(widthLoop, heightLoop))
                {
                    throw std::runtime_error("Could not move printer head to location.");
                }
            }
        }
    }
}
