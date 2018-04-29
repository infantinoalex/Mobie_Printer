#include "PrinterHead.hpp"
#include "../Exception/CustomExceptions.cpp"

#include <stdexcept>
#include <iostream>
#include <kipr/botball.h>

#define BUMPER_PORT 0
#define XHOME_SENSOR_PORT 9
#define YHOME_SENSOR_PORT 9
#define XMOTOR_PORT 2
#define YMOTOR_PORT 0
#define PRINTERHEAD_PORT 3
#define TICKS_BETWEEN_COORDINATES 200

PrinterHead::PrinterHead()
{
    this->_printerHeadPort = PRINTERHEAD_PORT;

    this->_xMotor = Motor(XMOTOR_PORT, TICKS_BETWEEN_COORDINATES, XHOME_SENSOR_PORT, BUMPER_PORT);
    this->_yMotor = Motor(YMOTOR_PORT, TICKS_BETWEEN_COORDINATES, YHOME_SENSOR_PORT, BUMPER_PORT);
 
    this->_isLowered = false;

    this->_minServoPosition = 0;
    this->_maxServoPosition = 2097;
}

void PrinterHead::LowerPrinter()
{
    if (this->_isLowered)
    {
        return;
    }

    enable_servos();
    set_servo_position(this->_printerHeadPort, this->_maxServoPosition);
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
    set_servo_position(this->_printerHeadPort, this->_minServoPosition);
    disable_servos();

    this->_isLowered = false;
}

bool PrinterHead::TryMovePrinterHead(int xDirectionToMove, int yDirectionToMove)
{
    try
    {
        int yDirectionToTicks = this->_yMotor.ConvertLocationToMoveToTicks(yDirectionToMove);
	std::cout << "Moving Y Direction" << std::endl;
        this->_yMotor.PowerMotorForNumberOfTicks(150, yDirectionToTicks);
    }
    catch (motor_exception exception)
    {
        return false;
    }

    try
    {
        int xDirectionToTicks = this->_xMotor.ConvertLocationToMoveToTicks(xDirectionToMove);
	std::cout << "Moving X Direction" << std::endl;
        this->_xMotor.PowerMotorForNumberOfTicks(150, xDirectionToTicks);
    }
    catch(motor_exception exception)
    {
        return false;
    }

    return true;
}

void PrinterHead::MovePrinterHeadHome()
{
    this->RaisePrinter();
    
    this->_xMotor.MoveHome();

    msleep(1000);

    this->_yMotor.MoveHome();

    msleep(1000);
}
