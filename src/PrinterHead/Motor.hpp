#ifndef MOTOR_HPP
#define MOTOR_HPP

class Motor
{
    public:
        Motor(int motorPort, int motorTravelLimit);

        void PowerMotor(int power);
        void PowerMotorAtVelocity(int velocity);
        void StopMotor();

        void PowerMotorForNumberOfTicks(int velocity, int ticks);

        int GetTotalTicks();
        int GetTicksSinceLastRequest();

    private:
        int _totalTicks;
        int _lastTicksCount;
        int _motorPort;
        int _motorTravelLimit;
};

#endif
