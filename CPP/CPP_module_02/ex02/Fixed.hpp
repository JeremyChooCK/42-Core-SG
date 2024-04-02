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
    Fixed operator-(const Fixed &fixed) const;
    Fixed operator+(const Fixed &fixed) const;
    Fixed operator*(const Fixed &fixed) const;
    Fixed operator/(const Fixed &fixed) const;
    bool operator<(const Fixed &fixed) const;
    bool operator<=(const Fixed &fixed) const;
    bool operator>(const Fixed &fixed) const;
    bool operator>=(const Fixed &fixed) const;
    bool operator==(const Fixed &fixed) const;
    bool operator!=(const Fixed &fixed) const;
    Fixed operator++();
    Fixed operator++(int);
    Fixed operator+=(const Fixed &fixed);
    Fixed operator--();
    Fixed operator--(int);
    Fixed operator-=(const Fixed &fixed);
    static Fixed max(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static Fixed min(const Fixed &a, const Fixed &b);
    static Fixed &min(Fixed &a, Fixed &b);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};
std::ostream	&operator<<(std::ostream &out, const Fixed &value);
#endif