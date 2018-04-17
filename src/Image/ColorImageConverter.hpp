#ifndef COLORIMAGECONVERTER_HPP
#define COLORIMAGECONVERTER_HPP

#include "ImageConverter.hpp"
#include "Colors.hpp"

#include <stdlib.h>
#include <map>

class ColorImageConverter : public ImageConverter
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
