#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>

class NotImplementedException
{
    public:
        virtual char const * what() const
        { 
            return "Fucntion not yet implemented.";
        }
};

#endif