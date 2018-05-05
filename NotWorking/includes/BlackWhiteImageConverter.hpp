#ifndef BLACKWHITEIMAGECONVERTER_HPP
#define BLACKWHITEIMAGECONVERTER_HPP

#include "Image.hpp"

class BlackWhiteImageConverter : public ImageConverter
{
    public:
        BlackWhiteImageConverter();

        // Overwritten to grab the image on a piece of paper and convert it to an Image
        // NOTE: This has not been tested at all and uses basic camera operations found on the wallaby.
        // do not even know if this will work.
        virtual Image GrabAndConvertImage();

    private:
        int _maxCameraHeight = 100;
        int _maxCameraWidth = 60;
        int _whiteCameraChannel = 5;
        int _biggestObjectIndex = 0;
};

#endif