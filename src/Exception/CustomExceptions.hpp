#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

class not_implemented_exception : public std::logic_error
{
    public:
        explicit not_implemented_exception(const std::string& what_arg)
            : std::logic_error(what_arg);

        explicit not_implemented_exception(const char* what_arg)
            : : std::logic_error(what_arg);
};

class drawing_exception : public std::logic_error
{
    public:
        explicit drawing_exception(const std::string& what_arg)
            : std::logic_error(what_arg);

        explicit drawing_exception(const char* what_arg)
            : std::logic_error(what_arg);
};

#endif
