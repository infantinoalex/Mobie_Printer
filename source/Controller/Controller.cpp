#include "Controller.hpp"

Controller::Controller(int bumperPort, Image image)
{
    if (bumperPort < 0 || bumperPort > 5)
    {
        throw invalid_argument("The provided bumper port must be between 0 - 5.")
    }

    if (image == NULL)
    {
        throw invalid_argument("The image must not be NULL.")
    }

    this->_bumperPort = bumperPort;
    this->_image = image;
}

bool Controller::IsStartBumperHit()
{
    if (digital(this->_bumperPort))
    {
        return true;
    }

    return false;
}

void Controller::GrabAndConvertImageData()
{
    throw new not_implemented_exception("The Controller::GrabAndConvertImageData function is not implemented yet.");
}

void Controller::DrawImage()
{
    throw new not_implemented_exception("The Controller::DrawImage function is not implemented yet.");
}