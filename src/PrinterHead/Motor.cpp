#include "Motor.hpp"

#include <kipr/botball.h>
#include <stdexcept>
#include <iostream>

Motor::Motor()
{
}

Motor::Motor(int motorPort, int ticksBetweenCoordinates, int homeSensorPort, int emergencySensorPort)
{
    if (motorPort < 0 || motorPort > 5)
    {
        throw std::invalid_argument("motorPort cannot be less than 0 or greater than 5");
    }

    if (ticksBetweenCoordinates < 0)
    {
        throw std::invalid_argument("ticksBetweenCoordinates cannot be less than 0.");
    }

    if (homeSensorPort < 0 || homeSensorPort > 9)
    {
        throw std::invalid_argument("homeSensorPort cannot be less than 0 or greater than 5");
    }

    if (emergencySensorPort < 0 || emergencySensorPort > 9)
    {
        throw std::invalid_argument("emergencySensorPort cannot be less than 0 or greater than 5");
    }

    this->_motorPort = motorPort;
    this->_ticksBetweenCoordinates = ticksBetweenCoordinates;

    this->_homeSensorPort = homeSensorPort;
    this->_correctHomeSensorValue = 200;

    this->_emergencySensorPort = emergencySensorPort;
}

void Motor::PowerMotorForNumberOfTicks(int velocity, int ticks)
{
    if (ticks < 0)
    {
        velocity *= -1;
    }

    if (digital(this->_emergencySensorPort))
    {
         this->StopMotor();
	 throw std::runtime_error("Failed when moving motor as the emergency stop button was hit");
    }
    int expectedTotalTickCounter = this->_totalTicks + ticks;
    
    mtp(this->_motorPort, velocity, expectedTotalTickCounter);
    bmd(this->_motorPort);

    this->StopMotor();
}

int Motor::ConvertLocationToMoveToTicks(int location)
{
    if (location < 0)
    {
        throw std::invalid_argument("location cannot be less than 0");
    }

    return (location * this->_ticksBetweenCoordinates) - this->_totalTicks;
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

void Motor::ClearMotorTicks()
{
    clear_motor_position_counter(this->_motorPort);
    this->_totalTicks = 0;
    this->_lastTicksCount = 0;
}

void Motor::StopMotor()
{
    motor_power(this->_motorPort, 0);
    this->_totalTicks = get_motor_position_counter(this->_motorPort);
    this->_lastTicksCount = this->_totalTicks - this->_lastTicksCount;
}
