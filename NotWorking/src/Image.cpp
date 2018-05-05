#include "../includes/Image.hpp"

#include <stdexcept>
#include <stdlib.h>
#include <iostream>

// Default constructor that initializes everything to NULL or 0
Image::Image()
{
    this->_width = 0;
    this->_height = 0;
}

// Sets the width and height of the image and creates a new array[height * width]
Image::Image(int width, int height)
{
    if (width <= 0)
    {
        throw std::invalid_argument("The width must be greater than 0.");
    }

    if (height <= 0)
    {
        throw std::invalid_argument("The height must be greater than 0.");
    }

    this->_width = width;
    this->_height = height;

    unsigned int testArray[width * height] = {0};
    this->_image = std::vector<unsigned int>(testArray, testArray + sizeof(testArray) / sizeof(testArray[0]));
}

// Sets the image based on the provided arguments
void Image::SetImage(std::vector<unsigned int> image, int width, int height)
{
    if (width <= 0)
    {
        throw std::invalid_argument("The width must be greater than 0.");
    }

    if (height <= 0)
    {
        throw std::invalid_argument("The height must be greater than 0.");
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
        throw std::invalid_argument("The X index cannot be less than 0.");
    }

    if (indexY < 0)
    {
        throw std::invalid_argument("The Y index cannot be less than 0.");
    }

    this->_image[this->_height  * indexY + indexX] = pixel;
}

// Gets the width of the image
int Image::GetImageWidth()
{
    return this->_width;
}

// Gest the height of the image
int Image::GetImageHeight()
{
    return this->_height;
}

// Gets the value of a pixel at a given index 
unsigned int Image::GetImagePixelAtIndex(int indexX, int indexY)
{
    if (indexX < 0)
    {
        throw std::invalid_argument("The X index cannot be less than 0.");
    }

    if (indexY < 0)
    {
        throw std::invalid_argument("The Y index cannot be less than 0.");
    }

    // Indexing the 1D array as though it was a 2D array
    return this->_image[this->_width * indexY + indexX];
}
