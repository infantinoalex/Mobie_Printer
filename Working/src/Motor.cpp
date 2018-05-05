#include "../includes/Motor.hpp"

#include <kipr/botball.h>
#include <stdexcept>
#include <iostream>

Motor::Motor()
{
}

Motor::Motor(int motorPort, int homeSensorPort)
{
    if (motorPort < 0 || motorPort > 5)
    {
        throw std::invalid_argument("motorPort cannot be less than 0 or greater than 5");
    }
    if (homeSensorPort < 0 || homeSensorPort > 9)
    {
        throw std::invalid_argument("homeSensorPort cannot be less than 0 or greater than 9");
    }

    this->_motorPort = motorPort;

    this->_homeSensorPort = homeSensorPort;
}

void Motor::MoveHome()
{
    while (!digital(this->_homeSensorPort))
    {
        motor(this->_motorPort, -10);
    }

    this->StopMotor();
    this->ClearMotorTicks();
}


void Motor::PowerMotor(int power)
{
    motor_power(this->_motorPort, power);
}

void Motor::StopMotor()
{
    motor_power(this->_motorPort, 0);
}
