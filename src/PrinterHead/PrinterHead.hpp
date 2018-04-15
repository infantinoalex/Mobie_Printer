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
        void MovePrinterHeadHome();

    private:
        Motor _xMotor;
        Motor _yMotor;
        int _printerHeadPort;
        bool _isLowered;

        int _maxServoPosition;
        int _minServoPosition;
};

#endif
