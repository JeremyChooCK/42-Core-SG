#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed const ab = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
    Fixed const bc = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
    Fixed const ca = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());

    // Check if the point is on the same side of all edges and not on any edge
    if ((ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0))
        return true;
    return false;
}