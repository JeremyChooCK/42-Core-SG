#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point &copy) : x(copy.x), y(copy.y) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::~Point() {}

Point &Point::operator=(const Point &copy) {
    if (this != &copy) {
        const_cast<Fixed&>(this->x) = copy.x;
        const_cast<Fixed&>(this->y) = copy.y;
    }
    return *this;
}

Fixed Point::getX(void) const {
    return this->x;
}

Fixed Point::getY(void) const {
    return this->y;
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "Point(" << point.getX() << ", " << point.getY() << ")";
    return out;
} 