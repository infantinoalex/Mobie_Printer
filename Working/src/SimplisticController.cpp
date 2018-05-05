#include "../includes/SimplisticController.hpp"

#include <iostream>
#include <stdexcept>

#define BUMPER_PORT 0

// Static method used to convert a Enum Colors to a string
static std::string ConvertColorToString(int color)
{
    std::string strings[] = { "Blue", "Red", "Yellow", "Green" };
    return strings[color];
}

SimplisticController::SimplisticController()
{
    this->_printerHead = PrinterHead();

    this->_bumperPort = BUMPER_PORT;
    this->_foundImageColor = Default;
}

bool SimplisticController::IsStartBumperHit()
{
    // Only returns true if the bumper has been hit
    if (digital(this->_bumperPort))
    {
        std::cout << "Bumper has been hit." << std::endl;
        return true;
    }

    return false;
}

void SimplisticController::GrabAndConvertImageData()
{
    std::cout << "Grabbing and converting the image from the camera." << std::endl;
    int colorChannelsArray[] = { (int)Blue, (int)Red, (int)Yellow, (int)Green };
    int loops = 0;
    while(true)
    {   
        // Used to determine if the camera polling has gone through too many loops so that it is not
        // looping forever
        if (loops > 2000)
        {
            camera_close();

            throw std::runtime_error("Camera could not find image in alloted time.");
        }

        int i;
        int numberOfChannels = sizeof(colorChannelsArray) / sizeof(colorChannelsArray[0]);
       
        camera_open();
	
	    std::cout << "Number of color channels " << numberOfChannels << std::endl;

        // Loops through all of the possible color channels that were defined to see if there is a color on the screen
        for (i = 0; i < numberOfChannels; ++i)
	    {
            while(!camera_update());

            // Checks to make sure there is an object and that the object is large enough area to not be a glitch
            if (get_object_count(colorChannelsArray[i]) && get_object_area(colorChannelsArray[i], 0) > 1000)
            {
                camera_close();

                std::cout << "Found color " << ConvertColorToString(i) << " on screen. Converting to image." << std::endl;
		        this->_foundImageColor = static_cast<Colors>(i);
		        return;
            }
        }

	    msleep(100);
        loops++;
    }
}

void SimplisticController::DrawImage()
{
    std::cout << "Moving printer head home before printing begins." << std::endl;

    this->_printerHead.MovePrinterHeadHome();
    msleep(100);
    
    // Simple switch to determine what to draw based upon the color we found
    switch(this->_foundImageColor)
    {
        case Blue:
            std::cout << "Drawing Blue Square" << std::endl;
            this->DrawSquare();
            break;

        case Red:
            std::cout << "Drawing Circle" << std::endl;
            this->DrawDiamond();
            break;

        case Green:
            std::cout << "Drawing Cross" << std::endl;
            this->DrawCross();
            break;

        case Yellow:
            std::cout << "Drawing multiple square outlines" << std::endl;
            this->DrawOutline();
            break;

        default:
            throw std::runtime_error("Could not find color to draw");
    }
}

void SimplisticController::DrawSquare()
{
    this->_printerHead.LowerPrinter();

    this->_printerHead.PowerXMotor(20);
    msleep(6000);
    this->_printerHead.StopXMotor();
    msleep(100);
    this->_printerHead.PowerYMotor(20);
    msleep(6000);
    this->_printerHead.StopYMotor();

    this->_printerHead.PowerXMotor(-20);
    msleep(6000);
    this->_printerHead.StopXMotor();
    msleep(100);
    this->_printerHead.PowerYMotor(-20);
    msleep(6000);
    this->_printerHead.StopYMotor();


    this->_printerHead.RaisePrinter();
}

void SimplisticController::DrawDiamond()
{
    this->_printerHead.RaisePrinter();

    this->_printerHead.PowerXMotor(20);
    msleep(2000);
    this->_printerHead.StopXMotor();
    this->_printerHead.LowerPrinter();
    msleep(100);
    this->_printerHead.PowerYMotor(20);
    this->_printerHead.PowerXMotor(20);
    msleep(2000);
    this->_printerHead.PowerYMotor(20);
    this->_printerHead.PowerXMotor(-20);
    msleep(2000);
    this->_printerHead.PowerYMotor(-20);
    this->_printerHead.PowerXMotor(-20);
    msleep(2000);
    this->_printerHead.PowerYMotor(-20);
    this->_printerHead.PowerXMotor(20);
    msleep(2000);
    this->_printerHead.StopXMotor();
    this->_printerHead.StopYMotor();

    this->_printerHead.RaisePrinter();
}

void SimplisticController::DrawCross()
{
    this->_printerHead.RaisePrinter();

    this->_printerHead.PowerXMotor(20);
    msleep(2000);
    this->_printerHead.StopXMotor();
    this->_printerHead.LowerPrinter();
    msleep(100);
    this->_printerHead.PowerYMotor(20);
    msleep(4000);
    this->_printerHead.PowerYMotor(-20);
    msleep(2000);
    this->_printerHead.StopYMotor();
    msleep(100);
    this->_printerHead.PowerXMotor(20);
    msleep(2000);
    this->_printerHead.PowerXMotor(-20);
    msleep(4000);
    this->_printerHead.StopXMotor();

    this->_printerHead.RaisePrinter();
}

void SimplisticController::DrawOutline()
{
    this->_printerHead.LowerPrinter();

    this->_printerHead.PowerXMotor(20);
    this->_printerHead.PowerYMotor(20);
    msleep(4000);
    this->_printerHead.StopXMotor();
    this->_printerHead.StopYMotor();
    this->_printerHead.RaisePrinter();
    msleep(100);
    this->_printerHead.PowerYMotor(-20);
    msleep(4000);
    this->_printerHead.StopYMotor();
    this->_printerHead.LowerPrinter();
    msleep(100);
    this->_printerHead.PowerYMotor(20);
    this->_printerHead.PowerXMotor(-20);
    msleep(4000);
    this->_printerHead.StopXMotor();
    this->_printerHead.StopYMotor();
    
    this->_printerHead.RaisePrinter();
}
