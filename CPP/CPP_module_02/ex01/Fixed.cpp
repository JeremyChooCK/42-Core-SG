#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed) {
        this->fixedPointValue = fixed.fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->fixedPointValue = raw;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(value * (1 << this->fractionalBits));
}

float Fixed::toFloat(void) const {
    return (float)this->fixedPointValue / (1 << this->fractionalBits);
}

int Fixed::toInt( void ) const{
    return fabs(this->fixedPointValue / (1 << this->fractionalBits));
}

std::ostream	&operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}