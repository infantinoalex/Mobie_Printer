#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>

/*
 * Internal representation of an image that is usable with the drawing algorithm.
 * Uses a bit array (values of 1 or 0) to determine if an image is white space (0) or black
 * space (1).
 */
class Image
{
    public:
        Image();
        Image(int width, int height);

        // Sets this image to the passed image object.
        void SetImage(std::vector<unsigned int> image, int width, int height);

        // Sets the value of the bit of the pixel of the image at the x, y coordinate provided.
        void SetImagePixelAtIndex(int indexX, int indexY, unsigned int pixel);

        // Gets the width of the image.
        int GetImageWidth();

        // Gets the height of the image.
        int GetImageHeight();

        // Gets the value of a pixel (either 1 or 0) at a given x and y index.
        unsigned int GetImagePixelAtIndex(int indexX, int indexY);

    private:
        // The 1-D array representation of the image.
	    std::vector<unsigned int> _image;

        // The width of the image.
        int _width;

        // The height of the image.
        int _height;
};

#endif
