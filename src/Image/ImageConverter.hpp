#ifndef IMAGECONVERTER_HPP
#define IMAGECONVERTER_HPP

#include "Image.hpp"

/*
 * Based class with a single method that must be overwritten. This determines how the printer will
 * process camera data.
 */
class ImageConverter
{
    public:
        // Grabs frames from the camera and created an Image object from them.
        virtual Image GrabAndConvertImage();
};

#endif
