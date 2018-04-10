#ifndef HELPER_HPP
#define HELPER_HPP

#include "Image/Colors.hpp"

#include <string>

static std::string ConvertColorToString(int color)
{
    std::string strings[] = { "Blue", "Red", "Yellow", "Green" };
    return strings[color];
}

#endif
