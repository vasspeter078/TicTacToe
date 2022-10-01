#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <vector>
#include <math.h>

#include "point.hpp"

class Player {
    std::vector<Point> steps;
    char symbol;
public:
    void addPoint(Point p);
    int getSize();
    char getSymbol();
    void setSymbol(char c);
    bool contains(Point p);
    bool wins();
private:
    bool hasFiveInLine();
    bool isHorizontal(std::vector<Point> points);
    bool isVertical(std::vector<Point> points);
    bool isDiagonal(std::vector<Point> points);
};

#endif // PLAYER_HPP_INCLUDED
