#include "player.hpp"

void Player::addPoint(Point p) {
    return steps.push_back(p);
}
int Player::getSize() {
    return steps.size();
}
char Player::getSymbol() {
    return symbol;
}
void Player::setSymbol(char c) {
    symbol = c;
}
bool Player::contains(Point p) {
    for (std::vector<Point>::iterator i = steps.begin(); i != steps.end(); ++i) {
        if (*i == p) {
            return true;
        }
    }
    return false;
}
bool Player::wins() {
    return hasFiveInLine();
}
bool Player::hasFiveInLine() {
    for (std::vector<Point>::iterator i1 = steps.begin(); i1 != steps.end(); ++i1) {
        for (std::vector<Point>::iterator i2 = i1 + 1; i2 != steps.end(); ++i2) {
            for (std::vector<Point>::iterator i3 = i2 + 1; i3 != steps.end(); ++i3) {
                for (std::vector<Point>::iterator i4 = i3 + 1; i4 != steps.end(); ++i4) {
                    for (std::vector<Point>::iterator i5 = i4 + 1; i5 != steps.end(); ++i5) {
                        std::vector<Point> points;
                        points.push_back(*i1);
                        points.push_back(*i2);
                        points.push_back(*i3);
                        points.push_back(*i4);
                        points.push_back(*i5);
                        if (isHorizontal(points) || isVertical(points) || isDiagonal(points)) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
bool Player::isHorizontal(std::vector<Point> points) {
    int maxDistance = 0;
    for (std::vector<Point>::iterator i1 = points.begin(); i1 != points.end(); ++i1) {
        for (std::vector<Point>::iterator i2 = i1 + 1; i2 != points.end(); ++i2) {
            if ((*i1).getY() != (*i2).getY()) {
                return false;
            }
            int distance = abs((*i1).getX() - (*i2).getX());
            if (distance > maxDistance) {
                maxDistance = distance;
            }
        }
    }
    if (maxDistance > 4) {
        return false;
    }
    return true;
}
bool Player::isVertical(std::vector<Point> points) {
    int maxDistance = 0;
    for (std::vector<Point>::iterator i1 = points.begin(); i1 != points.end(); ++i1) {
        for (std::vector<Point>::iterator i2 = i1 + 1; i2 != points.end(); ++i2) {
            if ((*i1).getX() != (*i2).getX()) {
                return false;
            }
            int distance = abs((*i1).getY() - (*i2).getY());
            if (distance > maxDistance) {
                maxDistance = distance;
            }
        }
    }
    if (maxDistance > 4) {
        return false;
    }
    return true;
}
bool Player::isDiagonal(std::vector<Point> points) {
    int maxDistance = 0;
    for (std::vector<Point>::iterator i1 = points.begin(); i1 != points.end(); ++i1) {
        for (std::vector<Point>::iterator i2 = i1 + 1; i2 != points.end(); ++i2) {
            if (abs((*i1).getX() - (*i2).getX()) != abs((*i1).getY() - (*i2).getY())) {
                return false;
            }
            int distance = abs((*i1).getX() - (*i2).getX());
            if (distance > maxDistance) {
                maxDistance = distance;
            }
        }
    }
    if (maxDistance > 4) {
        return false;
    }
    return true;
}
