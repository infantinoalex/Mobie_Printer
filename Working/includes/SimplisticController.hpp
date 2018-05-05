#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Colors.hpp"
#include "../includes/PrinterHead.hpp"

#include <stdexcept>
#include <iostream>
#include <kipr/botball.h>

/*
 * Main driver for the program. Contains the main methods that will be called
 * from main.cpp to controll the various parts of the printer.
 * 
 * TODO: Determine how to do constructor injection properly so that classes can be instantiated in
 *       main.cpp and passed via constructor.
 */
class SimplisticController
{
    public:
        SimplisticController();

        // Method that polls the port connected to the bumper.
        // Returns
        //      True - If the bumper was hit
        //      False - otherwise
        bool IsStartBumperHit();

        // Finds the color on the camera which dictates what to draw
        void GrabAndConvertImageData();

        // Based upon the Image object, sends control over to the motors to draw the image
        // on paper.
        void DrawImage();

    private:
        // Representation of the image seen internally
        Colors _foundImageColor;

        // The printer head object which controls the motors/pen for drawing
        PrinterHead _printerHead;

        // The port the bumper is using
        int _bumperPort;

        // Draws a square image
        void DrawSquare();

        // Draws a diamond image
        void DrawDiamond();

        // Draws a cross image
        void DrawCross();

        // Draws an X outline
        void DrawOutline();
};

#endif
