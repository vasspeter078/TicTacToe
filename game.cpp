#include "game.hpp"

Game::Game() {
    p1.setSymbol('x');
    p2.setSymbol('o');
    ap = player1;
}
void Game::draw() {
    std::cout<<" ";
    for (int i = 0; i < f.getFSize(); ++i) {
        std::cout<<" "<<i + 1;
    }
    std::cout<<std::endl;
    char **field = f.getField();
    for (int i = 0; i < f.getFSize() * 2 + 1; ++i) {
        for (int j = 0; j < f.getFSize() * 2 + 1 + 1; ++j) {
            if (i % 2 == 1 && j == 0) {
                std::cout<<(i + 1) / 2;
            }else {
                if (i % 2 == 0 && j == 0) {
                    std::cout<<" ";
                } else {
                    if (i % 2 == 1 && j % 2 == 0) {
                        Point p(j / 2, (i + 1) / 2);
                        if (p1.contains(p)) {
                            std::cout<<p1.getSymbol();
                        } else {
                            if (p2.contains(p)) {
                                std::cout<<p2.getSymbol();
                            } else {
                                std::cout<<field[i][j - 1];
                            }
                        }
                    } else {
                        std::cout<<field[i][j - 1];
                    }
                }
            }
        }
        if (i % 2 == 1) {
            std::cout<<(i + 1) / 2;
        }
        std::cout<<std::endl;
    }
    std::cout<<" ";
    for (int i = 0; i < f.getFSize(); ++i) {
        std::cout<<" "<<i + 1;
    }
    std::cout<<std::endl;
    /*
    for (int i = 0; i < f.getFSize(); ++i) {
        std::cout<<" "<<i + 1;
    }
    std::cout<<std::endl;
    char **field = f.getField();
    for (int i = 0; i < f.getFSize() * 2 + 1; ++i) {
        for (int j = 0; j < f.getFSize() * 2 + 1; ++j) {
            if (i % 2 == 1 && j % 2 == 1) {
                Point p((j + 1) / 2, (i + 1) / 2);
                if (p1.contains(p)) {
                    std::cout<<p1.getSymbol();
                } else {
                    if (p2.contains(p)) {
                        std::cout<<p2.getSymbol();
                    } else {
                        std::cout<<field[i][j];
                    }
                }
            } else {
                std::cout<<field[i][j];
            }
        }
        if (i % 2 == 1) {
            std::cout<<(i + 1) / 2;
        }
        std::cout<<std::endl;
    }
    for (int i = 0; i < f.getFSize(); ++i) {
        std::cout<<" "<<i + 1;
    }
    std::cout<<std::endl;
    */
}
void Game::menu() {
    std::cout<<"TICTACTOE"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Press any button to start"<<std::endl;
    getch();
    system("cls");
}
void Game::start() {
    bool gameOver = false;
    draw();
    while (!gameOver) {
        bool rightInput = false;
        Point p;
        while (!rightInput) {
            try {
                if (ap == player1) {
                    std::cout<<"Player1 x coordinate: ";
                } else {
                    std::cout<<"Player2 x coordinate: ";
                }
                int inpX;
                std::cin>>inpX;
                if (ap == player1) {
                    std::cout<<"Player1 y coordinate: ";
                } else {
                    std::cout<<"Player2 y coordinate: ";
                }
                int inpY;
                std::cin>>inpY;
                if (inpX > f.getFSize() || inpY > f.getFSize()) {
                    throw OutOfRange();
                }
                p.setX(inpX);
                p.setY(inpY);
                if (p1.contains(p) || p2.contains(p)) {
                    throw PointTaken();
                }
                rightInput = true;
            } catch (OutOfRange oof) {
                system("cls");
                draw();
                std::cout<<"This point is out of range"<<std::endl;
            } catch (PointTaken pt) {
                system("cls");
                draw();
                std::cout<<"This point is taken"<<std::endl;
            }
        }
        if (ap == player1) {
            p1.addPoint(p);
            ap = player2;
        } else {
            p2.addPoint(p);
            ap = player1;
        }
        system("cls");
        draw();
        if (p1.wins()) {
            std::cout<<"Player1 won";
            gameOver = true;
        }
        if (p2.wins()) {
            std::cout<<"Player2 won";
            gameOver = true;
        }
        if (p1.getSize() + p2.getSize() == f.getFSize() * f.getFSize()) {
            std::cout<<"Draw";
            gameOver = true;
        }
    }
}
