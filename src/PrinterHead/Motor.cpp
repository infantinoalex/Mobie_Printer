#include "Motor.hpp"
#include "../Exceptions/CustomExceptions.hpp"

#include <kipr/botball.h>
#include <stdexcept>

Motor::Motor(int motorPort. int ticksBetweenCoordinates, int homeSensorPort, int edgeSensorPort)
{
    if (motorPort < 0 || motorPort > 5)
    {
        throw invalid_argument("motorPort cannot be less than 0 or greater than 5");
    }

    if (ticksBetweenCoordinates < 0)
    {
        throw invalid_argument("ticksBetweenCoordinates cannot be less than 0.");
    }

    if (homeSensorPort < 0 || homeSensorPort > 5)
    {
        throw invalid_argument("homeSensorPort cannot be less than 0 or greater than 5");
    }

    if (edgeSensorPort < 0 || edgeSensorPort > 5)
    {
        throw invalid_argument("edgeSensorPort cannot be less than 0 or greater than 5");
    }

    this->_motorPort = motorPort;
    this->_ticksBetweenCoordinates = ticksBetweenCoordinates;

    this->_homeSensorPort = homeSensorPort;
    this->_edgeSensorPort = edgeSensorPort;

    // TODO: Need to be determined
    this->_correctHomeSensorValue = 200;
    this->_correctEdgeSensorValue = 200;
}

void Motor::PowerMotorForNumberOfTicks(int velocity, int ticks)
{
    int sensorPortToUse = this->_edgeSensorPort;
    int sensorValueToUse = this->_correctEdgeSensorValue;
    if (ticks < 0)
    {
        sensorPortToUse = this->_homeSensorPort;
        sensorValueToUse = this->_correctHomeSensorValue;
        velocity *= -1;
    }

    int expectedTotalTickCounter = this->_totalTicksCount + ticks;
    while (get_motor_position_counter != expectedTotalTickCounter)
    {
        this->PowerMotor(velocity);

        if (analog(sensorPortToUse) < sensorValueToUSe)
        {
            this->StopMotor();
            throw motor_exception("Failed when moving motor as it reached edge and wanted to still move");
        }
    }

    this->StopMotor();
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
    while (analog(this->_homeSensorPort) < this->_correctHomeSensorValue)
    {
        this->PowerMotor(1);
    }

    this->StopMotor();
    this->ClearMotorTicks();
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
