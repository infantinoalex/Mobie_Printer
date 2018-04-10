#include "Image.hpp"

#include <stdexcept>
#include <stdlib.h>

// Default constructor that initializes everything to NULL or 0
Image::Image()
{
    this->_width = 0;
    this->_height = 0;
    this->_resolution = 0;
    this->_image = NULL;
}

// Sets the width and height of the image and creates a new array[height * width]
Image::Image(int width, int height)
{
    if (width <= 0)
    {
        throw invalid_argument("The width must be greater than 0.")
    }

    if (height <= 0)
    {
        throw invalid_argument("The height must be greater than 0.")
    }

    this->_width = width;
    this->_height = height;

    this->_image = new unsigned int [this->_width * this->_height];
}

// Deletes the array
Image::~Image()
{
    this->_image = delete[];
}

// Sets the image based on the provided arguments
void Image::SetImage(unsigned int image[], int width, int height)
{
    if (image == NULL)
    {
        throw invalid_argument("The image cannot be null.")
    }

    if (width <= 0)
    {
        throw invalid_argument("The width must be greater than 0.")
    }

    if (height <= 0)
    {
        throw invalid_argument("The height must be greater than 0.")
    }

    this->_width = width;
    this->_height = height;

    this->_image = image;
}

// Sets the value of a pixel at a given index in the array
void Image::SetImagePixelAtIndex(int indexX, int indexY, unsigned int pixel)
{
    if (indexX < 0)
    {
        throw new invalid_argument("The X index cannot be less than 0.")
    }

    if (indexY < 0)
    {
        throw new invalid_argument("The Y index cannot be less than 0.")
    }

    this->_image[this->_height  * indexY + indexX] = pixel;
}

// Gets the width of the image
void Image::GetImageWidth()
{
    return this->_width;
}

// Gest the height of the image
void Image::GetImageHeight()
{
    return this->_height;
}

// Gets the value of a pixel at a given index 
unsigned int Image::GetImagePixelAtIndex(int indexX, int indexY)
{
    if (indexX < 0)
    {
        throw invalid_argument("The X index cannot be less than 0.")
    }

    if (indexY < 0)
    {
        throw invalid_argument("The Y index cannot be less than 0.")
    }

    return this->_image[this->_height * indexY + indexX];
}
