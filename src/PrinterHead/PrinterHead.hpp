#ifndef PRINTERHEAD_HPP
#define PRINTERHEAD_HPP

#include "Motor.hpp"

class PrinterHead
{
    public:
        PrinterHead(Motor xMotor, Motor yMotor, int printerHeadPort);

        void LowerPrinter();
        void RaisePrinter();

        bool TryMovePrinterHead(int xDirectionToMove, int yDirectionToMove);
        bool TryMovePrinterHeadHome();

    private:
        Motor _xMotor;
        Motor _yMotor;
        int _printerHeadPort;
        bool _isLowered;

        static int _maxServoPosition = 2097;
        static int _minServoPosition = 0;
};

#endif