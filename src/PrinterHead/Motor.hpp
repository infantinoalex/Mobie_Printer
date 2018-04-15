#ifndef MOTOR_HPP
#define MOTOR_HPP

class Motor
{
    public:
        Motor(int motorPort, int ticksBetweenCoordinates, int homeSensorPort, int edgeSensorPort);

        void PowerMotorForNumberOfTicks(int velocity, int ticks);
        int ConvertLocationToMoveToTicks(int location);
        void MoveHome();

    private:
        int _totalTicks;
        int _lastTicksCount;
        int _motorPort;
        int _ticksBetweenCoordinates;
        int _homeSensorPort;
        int _edgeSensorPort;
        int _correctHomeSensorValue;
        int _correctEdgeSensorValue;

        void PowerMotor(int power);
        void PowerMotorAtVelocity(int velocity);
        void StopMotor();
        void ClearMotorTicks();
};

#endif
