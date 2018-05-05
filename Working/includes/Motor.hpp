#ifndef MOTOR_HPP
#define MOTOR_HPP

/*
 * The internal representation for the motor.
 */
class Motor
{
    public:	
        Motor();
        Motor(int motorPort, int homeSensorPort);

        // Moves this motor to its home position
        void MoveHome();

        // Stops the motor
        void StopMotor();

        // Powers the motor with a given power
	    void PowerMotor(int power);


    private:
        // The port the motor is plugged into.
        int _motorPort;

        // The sensor used to determine if the motor has moved to the home position.
        int _homeSensorPort;
};

#endif
