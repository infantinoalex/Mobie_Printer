#ifndef MOTOR_HPP
#define MOTOR_HPP

/*
 * The internal representation for the motor.
 */
class Motor
{
    public:
	Motor();
        Motor(int motorPort, int ticksBetweenCoordinates, int homeSensorPort, int emergencySensorPort);

        // Powers the motor for the number of ticks provided.
        void PowerMotorForNumberOfTicks(int velocity, int ticks);

        // Converts a given location to ticks.
        int ConvertLocationToMoveToTicks(int location);

        // Moves this motor to its home position
        void MoveHome();

    private:
        // The total ticks the motor has moved since it arrived home.
        int _totalTicks;

        // The total ticks it has moved since the last time it has been moved.
        int _lastTicksCount;

        // The port the motor is plugged into.
        int _motorPort;

        // The number of ticks between coordinates (x1 -> x2)
        int _ticksBetweenCoordinates;

        // The sensor used to determine if the motor has moved to the home position.
        int _homeSensorPort;
        
        // The correct value used to determine if the motor has moved to the home position.
        int _correctHomeSensorValue;

        // The emergency sensor used to stop the motor.
        int _emergencySensorPort;

        void PowerMotor(int power);
        void PowerMotorAtVelocity(int velocity);
        void StopMotor();
        void ClearMotorTicks();
};

#endif
