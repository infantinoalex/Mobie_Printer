#include "../includes/SimplisticController.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    std::cout << "Robot Printer Started" << std::endl;
    std::cout << "Initializing Printer" << std::endl;

    // Initialize all classes here
  
    Controller controller = Controller();

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

	        msleep(1000);
        }

        std::cout << "Image has been drawn." << std::endl;
	    msleep(1000);
    }

    return 0;
}
