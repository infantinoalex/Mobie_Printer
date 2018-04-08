#include "Exception\Exception.hpp"
#include "Image\Image.hpp"
#include "Controller\Controller.hpp"
#include "Helper.hpp"

#include <iostream>
#include <stdlib>

int main(int argc, char ** argv)
{
    std::cout << "Robot Printer Started" << std::endl;

    std::cout << "Initializing Printer" << std::endl;

    // Initialize all classes here
    Image image;
    ImageConverter imageConverter;

    // If we will be looking for a color to make an image
    #ifdef Color

    
    
    #endif
    
    Controller controller = new Controller(BUMPER_PORT, image);

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