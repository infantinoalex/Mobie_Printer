#include "ColorImageConverter.hpp"
#include "..\Helper.hpp"

#include <stdexcept>

// Constructor that initialiazes the color channels to listen to and the color images
ColorImageConverter::ColorImageConverter(int colorChannels[], std::map<Colors, Image> colorImages)
{
    if (colorChannels == NULL)
    {
        throw new invalid_argument("colorChannels cannot be NULL");
    }

    if (colorImages == NULL)
    {
        throw new invalid_argument("colorImages cannot be NULL")
    }

    this->_colorChannels = _colorChannels;
    this->_colorImages = colorImages;
}

virtual Image ColorImageConverter::GrabAndConvertImage()
{
    int loops = 0;
    while(true)
    {
        if (loops > 200)
        {
            throw new camera_exception("Camera could not find image in alloted time.");
        }

        int i;
        int numberOfChannels = sizeof(this->_colorChannels) / sizeof(this->_colorChannels[0]);
       
        camera_open();

        for (i = 0; i < numberOfChannels; ++i)
        {
            while(!camera_update());

            if (get_object_count(this->_colorChannels[i]))
            {
                std::cout << "Found color " << ConvertColorToString(i) << "on screen. Converting to image." >> std::endl;

                return this->_colorImages.find(i);
            }
        }

        loops++;
    }
}