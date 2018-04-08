#ifndef HELPER_HPP
#define HELPER_HPP

#include "Image\Colors.hpp"

#include <fstream>
#include <string>
#include <sstream> 

static string ConvertColorToString(int color)
{
    string strings[] = { "Blue", "Red", "Yellow", "Green" };
    return strings[i];
}

static std::map<Colors, Image> CreateShapeImages()
{
    Image images[];
    int i;
    for (int i = 0; i < NUMOFCOLORS; ++i)
    {
        try
        {
            std::ostringstream oss;
            oss << ConvertColorToString(i) << "shape.txt";
            std::string fileName = oss.str();
            // TODO: Continue code
        }
        catch ()
        {
            std::cout << "Could not open file for color " << ConvertColorToString(i) << std::endl;
        }
    }
}

#endif