#include "PrinterHead.hpp"
#include "../Exception/CustomExceptions.hpp"

#include <stdexcept>

PrinterHead::PrinterHead(Motor xMotor, Motor yMotor, int printerHeadPort)
{
    if (printerHeadPort < 0 || printerHeadPort > 5)
    {
        throw invalid_argument("printerHeadPort must not be less than 0 or greater than 5.")
    }

    if (xMotor == NULL)
    {
        throw invalid_argument("xMotor must not be NULL.");
    }

    if (yMotor == NULL)
    {
        throw invalid_argument("yMotor must not be NULL.");
    }

    this->_printerHeadPort = printerHeadPort;

    this->_xMotor = xMotor;
    this->_yMotor = yMotor;

    this->_isLowered = false;
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
        int yDirectionToTicks this->_yMotor.ConvertLocationToMoveToTicks(yDirectionToMove);
        this->_yMotor.PowerMotorForNumberOfTicks(5, yDirectionToTicks);
    }
    catch (motor_exception exception)
    {
        return false;
    }

    try
    {
        int xDirectionToTicks = this->_xMotor.ConvertLocationToMoveToTicks(xDirectionToMove);
        this->_xMotor.PowerMotorForNumberOfTicks(5, xDirectionToTicks);
    }
    catch(motor_exception exception)
    {
        return false;
    }

    return true;
}

void PrinterHead::MovePrinterHeadHome()
{
    this->_xMotor.MoveHome();
    this->_yMotor.MoveHome();
}
