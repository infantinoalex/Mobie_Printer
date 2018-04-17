#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Image/Image.hpp"
#include "../Image/ImageConverter.hpp"
#include "../PrinterHead/PrinterHead.hpp"

#include <stdexcept>
#include <iostream>
#include <kipr/botball.h>

class Controller
{
    public:
        Controller();
        Controller(int bumperPort, ImageConverter &imageConverter, PrinterHead &printerHead);
	~Controller();

        bool IsStartBumperHit();
        void GrabAndConvertImageData();
        void DrawImage();
	void operator = (const Controller &controller);

    private:
        Image _image;
        ImageConverter _imageConverter;
        PrinterHead _printerHead;
        int _bumperPort;
};

#endif
