#include "Motor.hpp"

#include <kipr/botball.h>
#include <stdexcept>

Motor::Motor(int motorPort)
{
    if (motorPort < 0 || motorPort > 5)
    {
        throw new invalid_argument("motorPort cannot be less than 0 or greater than 5")
    }

    if (motorTravelLimit < 0)
    {
        throw new invalid_argument("motorTravelLimit cannot be less than 0.")
    }

    this->_motorPort = motorPort;
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

void Motor::PowerMotorForNumberOfTicks(int velocity, int ticks)
{
    mrp(this->_motorPort, velocity, ticks);
    this->_totalTicksCount = get_motor_position_counter(this->_motorPort);
    this->_lastTicksCount = this->_totalTicksCount - this->_lastTicksCount;
}

int Motor::GetTotalTicks()
{
    return this->_totalTicksCount;
}

int Motor::GetTicksSinceLastRequest()
{
    return this->_lastTicksCount;
}

void Motor::ClearMotorTicks()
{
    clear_motor_position_counter(this->_motorPort);
    this->_totalTicksCount = 0;
    this->_lastTicksCount = 0;
}

int Motor::ConvertTicksToLocation()
{
    throw not_implemented_exception("ConvertTicksToLocation not implemented yet")
}
