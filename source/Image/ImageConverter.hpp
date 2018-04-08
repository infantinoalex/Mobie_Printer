#ifndef IMAGECONVERTER_HPP
#define IMAGECONVERTER_HPP

#include "Image.hpp"

class ImageConverter
{
    public:
        virtual Image GrabAndConvertImage();
};

#endif