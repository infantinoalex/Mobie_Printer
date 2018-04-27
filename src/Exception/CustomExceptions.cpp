#ifndef EXCEPTIONS_CPP
#define EXCEPTIONS_CPP

#include <stdexcept>
#include <string>

// Exception thrown if a method is not yet implemented yet
// Notes
//      Mostly used during development
class not_implemented_exception : public std::logic_error
{
    public:
        explicit not_implemented_exception(const std::string& what_arg);

        explicit not_implemented_exception(const char* what_arg);
};

// Exception thrown if there is an error drawing the image
// Notes
//      If the emergency bumper is hit, this exception will occur
class drawing_exception : public std::runtime_error
{
    public:
        explicit drawing_exception(const std::string& what_arg);

        explicit drawing_exception(const char* what_arg);
};

// Exception thrown if the camera cannot determine what it is seeing.
// Notes
//      Thrown in the ImageConverter
class camera_exception : public std::runtime_error
{
    public:
        explicit camera_exception(const std::string& what_arg);

        explicit camera_exception(const char* what_arg);
};

// Exception thrown if there is some error with the motor
// Notes
//      If the motor goes to far and/or hits the home setting while it is trying to draw
class motor_exception : public std::runtime_error
{
    public:
        explicit motor_exception(const std::string& what_arg);

        explicit motor_exception(const char* what_arg);
};

#endif
