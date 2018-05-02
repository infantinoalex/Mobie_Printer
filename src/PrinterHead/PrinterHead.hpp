#ifndef PRINTERHEAD_HPP
#define PRINTERHEAD_HPP

#include "Motor.hpp"

/*
 * Internal representation of the printer head.
 * Contains the two motors that enable the printer head to move in the x and y direction.
 * Contains the servos motor to lower or raise the pen used for drawing.
 */
class PrinterHead
{
    public:
        PrinterHead();

        // If the printer head is not already lowered, lowers it.
        void LowerPrinter();

        // If the printer head is not already raised, raises it.
        void RaisePrinter();

        // Tries to move the printer head to the x y location provided.
        bool TryMovePrinterHead(int xDirectionToMove, int yDirectionToMove);

	void PowerXMotor(int power);
	void StopXMotor();
	void PowerYMotor(int power);
	void StopYMotor();

        // Moves the printer head back to the home position.
        void MovePrinterHeadHome();

    private:
        // The motor to move the printer head in the x direction.
        Motor _xMotor;

        // The motor to move the printer head in the y direction.
        Motor _yMotor;

        // The port for the servo that moves the printer head.
        int _printerHeadPort;

        // Bool used to determine if the printer head is already lowered or not.
        bool _isLowered;

        // The max position for the servo.
        int _maxServoPosition;

        // The min position for the servo.
        int _minServoPosition;
};

#endif
