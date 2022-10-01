#include "point.hpp"

int Point::getX() const {
    return x;
}
void Point::setX(int x) {
    this->x = x;
}
int Point::getY() const {
    return y;
}
void Point::setY(int y) {
    this->y = y;
}
bool Point::operator==(Point p) const {
    return x == p.x && y == p.y;
}
