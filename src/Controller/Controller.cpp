#include "Controller.hpp"

Controller::Controller(int bumperPort, ImageConverter ImageConverter, PrinterHead printerHead)
{
    if (bumperPort < 0 || bumperPort > 5)
    {
        throw invalid_argument("The provided bumper port must be between 0 - 5.")
    }

    if (imageConverter == NULL)
    {
        throw invalid_argument("The image must not be NULL.")
    }

    if (printerHead == NULL)
    {
        throw invalid_argument("The printer head must not be NULL.")
    }

    this->_bumperPort = bumperPort;
    this->_imageConverter = imageConverter;
    this->_printerHead = printerHead;
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

    int tryMovePrinterHeadHomeCounter = 0;
    while(!this->_printerHead.TryMovePrinterHeadHome())
    {
        tryMovePrinterHeadHomeCounter++;
        if (tryMovePrinterHeadHomeCounter > 25)
        {
            throw drawing_exception("Could not move printer head home within desired tries.")
        }
    }

    std::cout << "Printing out the pixels of the image." << std::endl;
    for (int heightLoop = 0; heightLoop < height; ++heightLoop)
    {
        if (heightLoop % 2 == 0)
        {
            for (int widthLoop = 0; widthLoop < width; ++widthLoop)
            {
                int pixelValue = this->_image.GetImagePixelAtIndex(widthLoop, indexLoop);
                if (pixelValue)
                {
                    this->_printerHead.LowerPrinter();
                }
                else
                {
                    this->_printerHead.RaisePrinter();
                }

                if (!TryMovePrinterHead(widthLoop, heightLoop))
                {
                    throw drawing_exception("Could not move printer head to location.")
                }
            }
        }
        else
        {
            for (int widthLoop = width - 1; widthLoop > -1; --widthLoop)
            {
                int pixelValue = this->_image.GetImagePixelAtIndex(widthLoop, indexLoop);
                if (pixelValue)
                {
                    this->_printerHead.LowerPrinter();
                }
                else
                {
                    this->_printerHead.RaisePrinter();
                }

                if (!TryMovePrinterHead(widthLoop, heightLoop))
                {
                    throw drawing_exception("Could not move printer head to location.")
                }
            }
        }
    }
}
