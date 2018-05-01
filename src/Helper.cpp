#ifndef HELPER_HPP
#define HELPER_HPP

#include "Image/Colors.hpp"
#include "Image/Image.hpp"

#include <string>
#include <map>
#include <iostream>
#include <vector>

/*
 * Contains static functions that are used throughout the program to make life easier.
 */

static std::map<Colors, Image> CreateShapeImages()
{
    std::map<Colors, Image> colorMap = std::map<Colors, Image>();

    unsigned int squareImage[] = 
    {
        0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,1,1,1,1,1,1,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,1,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0
    };

    int width = 10;
    int height = 10;

    std::vector<unsigned int> squareImageVector(squareImage, squareImage + sizeof(squareImage) / sizeof(squareImage[0]));
    Image BlueSquare = Image();
    BlueSquare.SetImage(squareImageVector, width, height);

    unsigned int circleImage[] =
    {
        0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,1,1,0,0,0,
	0,0,1,0,0,0,0,1,0,0,
	0,1,0,0,0,0,0,0,1,0,
	0,1,0,0,0,0,0,0,1,0,
	0,0,1,0,0,0,0,1,0,0,
	0,0,0,1,1,1,1,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
    };

    std::vector<unsigned int> circleImageVector(circleImage, circleImage + sizeof(circleImage) / sizeof(circleImage[0]));
    Image RedCircle = Image();
    RedCircle.SetImage(circleImageVector, width, height);

    colorMap.insert(std::pair<Colors, Image>(Blue, BlueSquare));
    colorMap.insert(std::pair<Colors, Image>(Red, RedCircle));

    return colorMap;
}

static std::string ConvertColorToString(int color)
{
    std::string strings[] = { "Blue", "Red", "Yellow", "Green" };
    return strings[color];
}

#endif
