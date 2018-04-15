#ifndef HELPER_HPP
#define HELPER_HPP

#include "Image/Colors.hpp"
#include "Image/Image.hpp"

#include <string>

static std::string ConvertColorToString(int color)
{
    std::string strings[] = { "Blue", "Red", "Yellow", "Green" };
    return strings[color];
}

static Image GetBlueSquareImage()
{
    unsigned int squareImage[] = { 0 };
    int width;
    int height;
    Image BlueSquare = Image();
    BlueSquare.SetImage(squareImage, width, height);
    return BlueSquare;
}

static Image GetRedCircleImage()
{
    unsigned int circleImage[] = { 0 };
    int width;
    int height;
    Image RedCircle = Image();
    RedCircle.SetImage(circleImage, width, height);
    return RedCircle;
}

#endif
