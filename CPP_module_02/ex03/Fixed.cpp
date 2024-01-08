#include "Fixed.hpp"

Fixed::Fixed() {
    this->fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &fixed) {
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    if (this != &fixed) {
        this->fixedPointValue = fixed.fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->fixedPointValue = raw;
}

Fixed::Fixed(const int value) {
    this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value) {
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

Fixed Fixed::operator+(const Fixed &fixed) const {
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    return Fixed(this->toFloat() / fixed.toFloat());
}

bool Fixed::operator<(const Fixed &fixed) const {
    return this->toFloat() < fixed.toFloat();
}

bool Fixed::operator<=(const Fixed &fixed) const {
    return this->toFloat() <= fixed.toFloat();
}

bool Fixed::operator>(const Fixed &fixed) const {
    return this->toFloat() > fixed.toFloat();
}

bool Fixed::operator>=(const Fixed &fixed) const {
    return this->toFloat() >= fixed.toFloat();
}

bool Fixed::operator==(const Fixed &fixed) const {
    return this->toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(const Fixed &fixed) const {
    return this->toFloat() != fixed.toFloat();
}

//++a is pre incrementation, so we need to return the value after incrementation
Fixed Fixed::operator++() {
    this->fixedPointValue++;
    return *this;
}
//a++ is post incrementation, so we need to return the value before incrementation
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed Fixed::operator+=(const Fixed &fixed) {
    this->fixedPointValue += fixed.fixedPointValue;
    return *this;
}
//--a is pre decrementation, so we need to return the value after decrementation
Fixed Fixed::operator--() {
    this->fixedPointValue--;
    return *this;
}
//a-- is post decrementation, so we need to return the value before decrementation
Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed Fixed::operator-=(const Fixed &fixed) {
    this->fixedPointValue -= fixed.fixedPointValue;
    return *this;
}

Fixed Fixed::max(const Fixed &a, const Fixed &b) {
    return a.toFloat() > b.toFloat() ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return a.toFloat() > b.toFloat() ? a : b;
}

Fixed Fixed::min(const Fixed &a, const Fixed &b) {
    return a.toFloat() < b.toFloat() ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return a.toFloat() < b.toFloat() ? a : b;
}