#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <stdexcept>
#include <stdlib.h>

class Image
{
    public:
        // Default constructor if image width and height is not known
        Image();

        // Constructor that sets the bitImage[width][height]
        Image(int width, int height);
        ~Image();

        // Sets the bitImage array to the image argument
        void SetImage(unsigned int ** image, int width, int height);

        // Sets the bit value of the bitImage[][] at a given index
        void SetImagePixelAtIndex(int indexX, int indexY, unsigned int pixel);

        // Gets the width of the image
        int GetImageWidth();

        // Gets the height of the iamge
        int GetImageHeight();

        // Gets the bit value of the image at a given index
        unsigned int GetImagePixelAtIndex(int indexX, int indexY);

    private:
        unsigned int _image[];
        int _width;
        int _height;
}

#endif