#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>

class not_implemented_exception
{
    public:
        explicit not_implemented_exception(const string& what_arg)
        : base (what_arg)
        { 
        };

        explicit not_implemented_exception(const char* what_arg)
        : base (what_arg)
        {
        };
};

#endif