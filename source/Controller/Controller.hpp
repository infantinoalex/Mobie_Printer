#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Image/Image.hpp"
#include "../Exception/CustomExceptions.hpp"

#include <stdexcept>
#include <kipr/botball.h>

class Controller
{
    public:
        Controller(int bumperPort, ImageConverter ImageConverter, PrinterHead printerHead);
        ~Controller();

        bool IsStartBumperHit();
        void GrabAndConvertImageData();
        void DrawImage();

    private:
        Image _image;
        ImageConverter _imageConverter;
        int _bumperPort;
};

#endif
