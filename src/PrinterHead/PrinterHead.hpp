#ifndef PRINTERHEAD_HPP
#define PRINTERHEAD_HPP

#include "Motor.hpp"

class PrinterHead
{
    public:
        PrinterHead(int xMotorPort, int yMotorPort, int printerHeadPort);

        void LowerPrinter();
        void RaisePrinter();

        bool TryMovePrinterHead(int xDirectionToMove, int yDirectionToMove);
        bool TryMovePrinterHeadHome();

        int GetXMotorLocation();
        int GetYMotorLocation();

    private:
        Motor _xMotor;
        Motor _yMotor;
        int _printerHeadPort;
        bool _isLowered;
};

#endif