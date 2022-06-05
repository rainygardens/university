#ifndef exceptions_hpp
#define exceptions_hpp

#include <stdexcept>
#include <string>

class wyjatek_wymierny : public std::logic_error {
    public:
        wyjatek_wymierny(const char *msg) : std::logic_error(msg)
        {};
};


class rationalDivisionByZero : public wyjatek_wymierny {
    public:
        rationalDivisionByZero(const char *msg) : wyjatek_wymierny(msg) {
            std::cerr << msg << " ";
            std::cerr << "Cannot divide by 0! Constructor syntax: wymierna::wymierna(integer numerator, integer denumerator)" << std::endl;
        };
};

class rationalNegativeDenumerator : public wyjatek_wymierny {
    public:
        rationalNegativeDenumerator(const char *msg) : wyjatek_wymierny(msg) {
            std::cerr << msg << " ";
            std::cerr << "Given denumerator is a negative number! The number will be converted." << std::endl;
        };
};


#endif