#include "Exception/CustomExceptions.hpp"
#include "Image/Image.hpp"
#include "Controller/Controller.hpp"
#include "Helper.hpp"
#include "Image/Colors.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <map>
#include <stdlib.h>

#define BUMPER_PORT 0
#define NUMOFCOLORS 4

std::map<Colors, Image> CreateShapeImages()
{
    std::map<Colors, Image> colorMap = std::map<Colors, Image>();
    int i;
    for (int i = 0; i < NUMOFCOLORS; ++i)
    {
        try
        {
            std::ostringstream oss;
            oss << "Resources/" << ConvertColorToString(i) << "shape.txt";
            std::string fileName = oss.str();
            ifstream inFile;
            inFile.open(fileName);

            Image image = Image(44, 22);

            int yRow = 0;
            int xColumn = 0;
            char value;
            while(inFile.get(value))
            {
                if (value == '\n')
                {
                    yRow++;
                    xColumn = 0;
                }
                else if (value == '1')
                {
                    image.SetImagePixelAtIndex(xColumn, yRow, 1);
                }
                else
                {
                    image.SetImagePixelAtIndex(xColumn, yRow, 0);
                }
            }

            colorMap.insert(std::pair<Colors, Image>((Colors)i, image));
        }
        catch ()
        {
            std::cout << "Could not open file for color " << ConvertColorToString(i) << std::endl;
        }
    }

    return colorMap;
}

int main(int argc, char ** argv)
{
    std::cout << "Robot Printer Started" << std::endl;

    std::cout << "Initializing Printer" << std::endl;

    // Initialize all classes here
    Image image;
    ImageConverter imageConverter;
    Motor xMotor, yMotor;
    PrinterHead printerHead;

    // If we will be looking for a color to make an image
    #ifdef Color

    int colorChannels[] = { 0, 1, 2, 3 };

    std::map<Colors, Image> colorsMap = CreateShapeImages();
    imageConverter = ColorImageConverter(colorChannels, colorsMap);
    
    #endif
    
    Controller controller = Controller(BUMPER_PORT, imageConverter, printerHead);

    // End Initialization

    std::cout << "Printer Initialized" << std::endl;

    while(true)
    {
        std::cout << "Waiting for Start Bumper to be hit to begin" << std::endl;
        while(!controller.IsStartBumperHit());

        std::cout << "Start Bumper hit. Polling camera for image" << std::endl;
        controller.GrabAndConvertImageData();

        std::cout << "Image grabbed and converted" << std::endl;
        std::cout << "Drawing image" << std::endl;

        controller.DrawImage();
        std::cout << "Image has been drawn" << std::endl;
    }

    return 0;
}
