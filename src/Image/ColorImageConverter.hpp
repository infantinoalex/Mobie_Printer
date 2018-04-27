#ifndef COLORIMAGECONVERTER_HPP
#define COLORIMAGECONVERTER_HPP

#include "ImageConverter.hpp"
#include "Colors.hpp"

#include <stdlib.h>
#include <map>

/*
 * Will poll the camera for simple colors and based upon there values, grab a predetermined object from the map that is
 * passed to it via its constructor.
 */
class ColorImageConverter : public ImageConverter
{
    public:
        ColorImageConverter(int colorChannels[], std::map<Colors, Image> colorImages);
        ~ColorImageConverter();

        // Ovwritten to grab a pretermined image based upon a color.
        virtual Image GrabAndConvertImage();

    private:
        // The current color channels setup on the wallaby.
        int _colorChannels[];

        // A map used to map an Color to an Image
        std::map<Colors, Image> _colorImages;
};

#endif
