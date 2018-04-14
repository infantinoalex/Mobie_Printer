#ifndef MOTOR_HPP
#define MOTOR_HPP

class Motor
{
    // TODO: Add sensor port to help determine if motor has gone too far or if it has reached its home position
    public:
        Motor(int motorPort);

        void PowerMotor(int power);
        void PowerMotorAtVelocity(int velocity);
        void StopMotor();

        void PowerMotorForNumberOfTicks(int velocity, int ticks);

        int GetTotalTicks();
        int GetTicksSinceLastRequest();

        void ClearMotorTicks();

    private:
        int _totalTicks;
        int _lastTicksCount;
        int _motorPort;

        int ConvertTicksToLocation();
};

#endif
