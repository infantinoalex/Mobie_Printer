#include "Controller.hpp"

Controller::Controller(int bumperPort, ImageConverter ImageConverter)
{
    if (bumperPort < 0 || bumperPort > 5)
    {
        throw invalid_argument("The provided bumper port must be between 0 - 5.")
    }

    if (imageConverter == NULL)
    {
        throw invalid_argument("The image must not be NULL.")
    }

    this->_bumperPort = bumperPort;
    this->_imageConverter = imageConverter;
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
    this->_image = this->_imageConverter.GrabAndConvertImage();
}

void Controller::DrawImage()
{
    throw new not_implemented_exception("The Controller::DrawImage function is not implemented yet.");
}
