#include "Motor.hpp"

#include <kipr/botball.h>
#include <stdexcept>

Motor::Motor(int motorPort. int ticksBetweenCoordinates)
{
    if (motorPort < 0 || motorPort > 5)
    {
        throw new invalid_argument("motorPort cannot be less than 0 or greater than 5")
    }

    if (ticksBetweenCoordinates < 0)
    {
        throw new invalid_argument("ticksBetweenCoordinates cannot be less than 0.")
    }

    this->_motorPort = motorPort;
    this->_ticksBetweenCoordinates = ticksBetweenCoordinates;
}

void Motor::PowerMotorForNumberOfTicks(int velocity, int ticks)
{
    // TODO: while (if ticks is negative, move while home sensor not hit)
    // if ticks is positive, move while target sensor is not hit
    // If sensor is hit, throw motor moving exception
    mrp(this->_motorPort, velocity, ticks);
    this->_totalTicksCount = get_motor_position_counter(this->_motorPort);
    this->_lastTicksCount = this->_totalTicksCount - this->_lastTicksCount;
}

int Motor::ConvertLocationToMoveToTicks(int location)
{
    if (location < 0)
    {
        throw invalid_argument("location cannot be less than 0");
    }

    return (location * this->_ticksBetweenCoordinates) - this->_totalTicksCount;
}

void Motor::MoveHome()
{
    // TODO: while sensor not hit, move negative
    // once sensor hit return
    throw not_implemented_exception("MoveHome not implemented yet.")
}

void Motor::ClearMotorTicks()
{
    clear_motor_position_counter(this->_motorPort);
    this->_totalTicksCount = 0;
    this->_lastTicksCount = 0;
}

void Motor::PowerMotor(int power)
{
    motor_power(this->_motorPort, power);
}

void Motor::PowerMotorAtVelocity(int velocity)
{
    motor(this->_motorPort, velocity);
}

void Motor::StopMotor()
{
    motor_power(this->_motorPort, 0);
    this->_totalTicksCount = get_motor_position_counter(this->_motorPort);
    this->_lastTicksCount = this->_totalTicksCount - this->_lastTicksCount;
}