#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <iostream>
#include <conio.h>

#include "player.hpp"
#include "field.hpp"
#include "outofrange.hpp"
#include "pointtaken.hpp"
#include "activeplayer.hpp"

class Game {
    Player p1;
    Player p2;
    Field f;
    ActivePlayer ap;
public:
    Game();
    void draw();
    void menu();
    void start();
};

#endif // GAME_HPP_INCLUDED
