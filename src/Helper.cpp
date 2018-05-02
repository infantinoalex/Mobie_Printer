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
    int width = 10;
    int height = 24;


    unsigned int squareImage[] = 
    {
        0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,1,1,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,1,1,0,
        0,1,1,1,1,1,1,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,
	0,1,1,1,1,1,1,1,1,0,
	0,1,1,1,1,1,1,1,1,0,
	0,1,1,1,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0
    };

    std::vector<unsigned int> squareImageVector(squareImage, squareImage + sizeof(squareImage) / sizeof(squareImage[0]));
    Image BlueSquare = Image();
    BlueSquare.SetImage(squareImageVector, width, height);

    unsigned int circleImage[] =
    {
        0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,1,1,0,0,0,
	0,0,0,1,1,1,1,0,0,0,
	0,0,0,1,1,1,1,0,0,0,
	0,0,1,0,0,0,0,1,0,0,
	0,0,1,0,0,0,0,1,0,0,
	0,0,1,0,0,0,0,1,0,0,
	0,1,0,0,0,0,0,0,1,0,
	0,1,0,0,0,0,0,0,1,0,
	0,1,0,0,0,0,0,0,1,0,
	0,1,0,0,0,0,0,0,1,0,
	0,1,0,0,0,0,0,0,1,0,
	0,1,0,0,0,0,0,0,1,0,
	0,0,1,0,0,0,0,1,0,0,
	0,0,1,0,0,0,0,1,0,0,
	0,0,1,0,0,0,0,1,0,0,
	0,0,0,1,1,1,1,0,0,0,
	0,0,0,1,1,1,1,0,0,0,
	0,0,0,1,1,1,1,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0
    };

    std::vector<unsigned int> circleImageVector(circleImage, circleImage + sizeof(circleImage) / sizeof(circleImage[0]));
    Image RedCircle = Image();
    RedCircle.SetImage(circleImageVector, width, height);

    unsigned int outlineImage[] =
    {
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,1,
        1,0,1,1,1,1,1,1,0,1,
        1,0,1,1,1,1,1,1,0,1,
        1,0,1,1,1,1,1,1,0,1,
        1,0,1,0,0,0,0,1,0,1,
        1,0,1,0,0,0,0,1,0,1,
        1,0,1,0,1,1,0,1,0,1,
        1,0,1,0,1,1,0,1,0,1,
        1,0,1,0,1,1,0,1,0,1,
        1,0,1,0,1,1,0,1,0,1,
        1,0,1,0,0,0,0,1,0,1,
        1,0,1,0,0,0,0,1,0,1,
        1,0,1,1,1,1,1,1,0,1,
        1,0,1,1,1,1,1,1,0,1,
        1,0,1,1,1,1,1,1,0,1,
        1,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1
    };

    std::vector<unsigned int> outlineImageVector(outlineImage, outlineImage + sizeof(outlineImage) / sizeof(outlineImage[0]));
    Image OutlineImage = Image();
    OutlineImage.SetImage(outlineImageVector, width, height);

    unsigned int crossMarkImage[] =
    {
        1,1,0,0,0,0,0,0,1,1,
        1,1,0,0,0,0,0,0,1,1,
        1,1,0,0,0,0,0,0,1,1,
        0,1,1,0,0,0,0,1,1,0,
        0,1,1,0,0,0,0,1,1,0,
        0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,
        0,0,0,1,1,1,1,0,0,0,
        0,0,0,1,1,1,1,0,0,0,
        0,0,0,0,1,1,0,0,0,0,
        0,0,0,0,1,1,0,0,0,0,
        0,0,0,0,1,1,0,0,0,0,
        0,0,0,0,1,1,0,0,0,0,
        0,0,0,0,1,1,0,0,0,0,
        0,0,0,0,1,1,0,0,0,0,
        0,0,0,1,1,1,1,0,0,0,
        0,0,0,1,1,1,1,0,0,0,
        0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,
        0,1,1,0,0,0,0,1,1,0,
        0,1,1,0,0,0,0,1,1,0,
        1,1,0,0,0,0,0,0,1,1,
        1,1,0,0,0,0,0,0,1,1,
        1,1,0,0,0,0,0,0,1,1
    };

    std::vecotor<unsigned int> crossMarkImageVector(crossMarkImage, crossMarkImage + sizeof(crossMarkImage) / sizeof(crossMarkImage[0]));
    Image CrossMarkImage = Image();
    CrossMarkImage.SetImage(crossMarkImageVector, width, height);

    colorMap.insert(std::pair<Colors, Image>(Blue, BlueSquare));
    colorMap.insert(std::pair<Colors, Image>(Red, RedCircle));
    colorMap.insert(std::pair<Colors, Image>(Green, OutlineImage));
    colorMap.insert(std::pair<Colors, Image>(Yellow, CrossMarkImage));

    return colorMap;
}

static std::string ConvertColorToString(int color)
{
    std::string strings[] = { "Blue", "Red", "Yellow", "Green" };
    return strings[color];
}

#endif
