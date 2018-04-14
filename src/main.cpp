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

static std::map<Colors, Image> CreateShapeImages()
{
    std::map<Colors, Image> colorMap = std::map<Colors, Image>();

    colorMap.insert(std::pair<Colors, Image>(Colors.Blue, GetBlueSquareImage()));
    colorMap.insert(std::pair<Colors, Image>(Colors.Red, GetRedCircleImage()));

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

    int colorChannels[] = { (int)Colors.Blue, (int)Colors.Red, (int)Colors.Yellow, (int)Colors.Green };

    std::map<Colors, Image> colorsMap = CreateShapeImages();
    imageConverter = ColorImageConverter(colorChannels, colorsMap);
        
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

        try
        {
            controller.DrawImage();
        }
        catch (std::exception exception)
        {
            std::cout << "Caught exception while trying to draw image." << std::endl;
            std::cout << "Failed to draw image. Please try again." << std::endl;
            std::cout << "Exception: " << exception.what() << std::endl;
        }

        std::cout << "Image has been drawn." << std::endl;
    }

    return 0;
}
