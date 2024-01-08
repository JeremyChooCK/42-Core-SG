#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point {
    public:
        Point();
        Point(const Point &copy);
        Point(const float x, const float y);
        ~Point();
        Point &operator=(const Point &copy);
        Fixed getX(void) const;
        Fixed getY(void) const;
    private:
        Fixed const x;
        Fixed const y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif