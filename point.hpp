#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED

class Point {
protected:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) :x(x), y(y) {}
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    bool operator==(Point p) const;
};

#endif // POINT_HPP_INCLUDED
