#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>
#include <cmath>

class Fixed {
private:
    int fixedPointValue;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const Fixed &fixed);
    Fixed(const float value);
    Fixed &operator=(const Fixed &fixed);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};
std::ostream	&operator<<(std::ostream &out, const Fixed &value);
#endif