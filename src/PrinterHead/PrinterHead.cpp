#include "PrinterHead.hpp"

#include <stdexcept>
#include <iostream>
#include <kipr/botball.h>

#define BUMPER_PORT 0
#define XHOME_SENSOR_PORT 8
#define YHOME_SENSOR_PORT 8
#define XMOTOR_PORT 2
#define YMOTOR_PORT 0
#define PRINTERHEAD_PORT 3
#define X_TICKS_BETWEEN_COORDINATES 150
#define Y_TICKS_BETWEEN_COORDINATES 150

PrinterHead::PrinterHead()
{
    this->_printerHeadPort = PRINTERHEAD_PORT;

    this->_xMotor = Motor(XMOTOR_PORT, X_TICKS_BETWEEN_COORDINATES, XHOME_SENSOR_PORT, BUMPER_PORT);
    this->_yMotor = Motor(YMOTOR_PORT, Y_TICKS_BETWEEN_COORDINATES, YHOME_SENSOR_PORT, BUMPER_PORT);
 
    this->_isLowered = true;

    this->_minServoPosition = 1100;
    this->_maxServoPosition = 500;
}

void PrinterHead::LowerPrinter()
{
    if (this->_isLowered)
    {
        return;
    }

    enable_servos();
    msleep(500);
    set_servo_position(this->_printerHeadPort, this->_maxServoPosition);
    msleep(500);
    disable_servos();

    this->_isLowered = true;
}

void PrinterHead::RaisePrinter()
{
    if (!this->_isLowered)
    {
        return;
    }

    enable_servos();
    msleep(500);
    set_servo_position(this->_printerHeadPort, this->_minServoPosition);
    msleep(500);
    disable_servos();

    this->_isLowered = false;
}

bool PrinterHead::TryMovePrinterHead(int xDirectionToMove, int yDirectionToMove)
{
    try
    {
        int yDirectionToTicks = this->_yMotor.ConvertLocationToMoveToTicks(yDirectionToMove);
        this->_yMotor.PowerMotorForNumberOfTicks(150, yDirectionToTicks);
    }
    catch (std::exception exception)
    {
        std::cout << "Caught exception while trying to draw in the Y direction" << std::endl;
        return false;
    }

    try
    {
        int xDirectionToTicks = this->_xMotor.ConvertLocationToMoveToTicks(xDirectionToMove);
        this->_xMotor.PowerMotorForNumberOfTicks(150, xDirectionToTicks);
    }
    catch(std::exception exception)
    {
        std::cout << "Caught exception while trying to draw in the X directoin" << std::endl;
        return false;
    }

    return true;
}

void PrinterHead::PowerXMotor(int power)
{
    this->_xMotor.PowerMotor(power);
}

void PrinterHead::StopXMotor()
{
    this->_xMotor.StopMotor();
}

void PrinterHead::PowerYMotor(int power)
{
    this->_yMotor.PowerMotor(power);
}

void PrinterHead::StopYMotor()
{
    this->_yMotor.StopMotor();
}

void PrinterHead::MovePrinterHeadHome()
{
    this->RaisePrinter();

    msleep(1000);
    this->_xMotor.MoveHome();

    msleep(1000);
    this->_yMotor.MoveHome();

    msleep(1000);
    this->_yMotor.ClearMotorTicks();
    this->_xMotor.ClearMotorTicks();
}
