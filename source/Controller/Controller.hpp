#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "..\Image\Image.hpp"
#include "..\Exception\Exception.hpp"

#include <stdexcept>
#include <kipr/botball.h>

class Controller
{
    public:
        Controller(int bumperPort, Image image);
        ~Controller();

        bool IsStartBumperHit();
        void GrabAndConvertImageData();
        void DrawImage();

    private:
        Image _image;
        int _bumperPort;
};

#endif