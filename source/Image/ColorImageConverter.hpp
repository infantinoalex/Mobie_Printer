#ifndef COLORIMAGECONVERTER_HPP
#define COLORIMAGECONVERTER_HPP

#include "ImageConverter.hpp"

#include <stdlib>
#include <stdexcept>

class ColorImageConverter : ImageConverter
{
    public:
        ColorImageConverter(int colorChannels[], std::map<Colors, Image> colorImages);
        ~ColorImageConverter();

        virtual Image GrabAndConvertImage();

    private:
        int _colorChannels[];
        std::map<Colors, Image> _colorImages;
};

#endif