#ifndef MOTOR_HPP
#define MOTOR_HPP

class Motor
{
    // TODO: Add sensor port to help determine if motor has gone too far or if it has reached its home position
    public:
        Motor(int motorPort, int ticksBetweenCoordinates);

        void PowerMotorForNumberOfTicks(int velocity, int ticks);
        int ConvertLocationToMoveToTicks(int location);
        void ClearMotorTicks();
        void MoveHome();

    private:
        int _totalTicks;
        int _lastTicksCount;
        int _motorPort;
        int _ticksBetweenCoordinates;

        void PowerMotor(int power);
        void PowerMotorAtVelocity(int velocity);
        void StopMotor();
};

#endif
