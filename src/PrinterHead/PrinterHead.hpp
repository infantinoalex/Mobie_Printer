#ifndef PRINTERHEAD_HPP
#define PRINTERHEAD_HPP

#include "Motor.hpp"

class PrinterHead
{
    public:
        PrinterHead(int xMotorPort, int yMotorPort, int printerHeadPort);

        void LowerPrinter();
        void RaisePrinter();

        bool MovePrinterHead(int xDirectionToMove, int yDirectionToMove);

        int GetXMotorLocation();
        int GetYMotorLocation();

    private:
        Motor _xMotor;
        Motor _yMotor;
        int _printerHeadPort;
};

#endif