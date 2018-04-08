#include "PrinterHead.hpp"
#include "..\Exception\CustomExceptions.hpp"

#include <stdexcept>

PrinterHead::PrinterHead(int printerHeadPort, Motor xMotor, Motor yMotor)
{
    if (printerHeadPort < 0 || printerHeadPort > 5)
    {
        throw invalid_argument("printerHeadPort must not be less than 0 or greater than 5.")
    }

    if (xMotor == NULL)
    {
        throw invalid_argument("xMotor must not be NULL.");
    }

    if (yMotor)
    {
        throw invalid_argument("yMotor must not be NULL.");
    }

    this->_printerHeadPort = printerHeadPort;

    this->_xMotor = xMotor;
    this->_yMotor = yMotor;
}

void PrinterHead::LowerPrinter()
{
    throw not_implemented_exception("LowerPrinter is not implemented yet");
}

void PrinterHead::RaisePrinter()
{
    throw not_implemented_exception("RaisePrinter is not implemented yet");
}

bool PrinterHead::MovePrinterHead(int xDirectionToMove, int yDirectionToMove)
{
    throw not_implemented_exception("MovePrinterHead is not implemented yet");
}

int PrinterHead::GetXMotorLocation()
{
    throw not_implemented_exception("GetXMotorLocation is not implemented yet");
}

int PrinterHead::GetYMotorLocation()
{
    throw not_implemented_exception("GetYMotorLocation is not implemented yet");
}