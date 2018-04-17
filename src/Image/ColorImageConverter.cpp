#include "ColorImageConverter.hpp"
#include "Colors.hpp"
#include "../Helper.cpp"
#include "../Exception/CustomExceptions.cpp"

#include <stdexcept>
#include <kipr/botball.h>
#include <iostream>

ColorImageConverter::ColorImageConverter(int colorChannels[], std::map<Colors, Image> colorImages)
{
    this->_colorChannels = _colorChannels;
    this->_colorImages = colorImages;
}

Image ColorImageConverter::GrabAndConvertImage()
{
    int loops = 0;
    while(true)
    {
        if (loops > 200)
        {
            camera_close();

            throw camera_exception("Camera could not find image in alloted time.");
        }

        int i;
        int numberOfChannels = sizeof(this->_colorChannels) / sizeof(this->_colorChannels[0]);
       
        camera_open();

        for (i = 0; i < numberOfChannels; ++i)
        {
            while(!camera_update());

            if (get_object_count(this->_colorChannels[i]))
            {
                camera_close();

                std::cout << "Found color " << ConvertColorToString(i) << "on screen. Converting to image." << std::endl;

		Colors colorValue = static_cast<Colors>(i);
                return this->_colorImages[colorValue];
            }
        }

        loops++;
    }
}
