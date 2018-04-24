#ifndef MOTOR_HPP
#define MOTOR_HPP

class Motor
{
    public:
	Motor();
        Motor(int motorPort, int ticksBetweenCoordinates, int homeSensorPort, int emergencySensorPort);

        void PowerMotorForNumberOfTicks(int velocity, int ticks);
        int ConvertLocationToMoveToTicks(int location);
        void MoveHome();

    private:
        int _totalTicks;
        int _lastTicksCount;
        int _motorPort;
        int _ticksBetweenCoordinates;
        int _homeSensorPort;
        int _correctHomeSensorValue;
        int _emergencySensorPort;

        void PowerMotor(int power);
        void PowerMotorAtVelocity(int velocity);
        void StopMotor();
        void ClearMotorTicks();
};

#endif
