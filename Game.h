#ifndef GAME.H
#define GAME.H
#include <iostream>
#include "Player.h"

class Game
{
    private:
    int numShips;
    Player player1;
    Player player2;

    public:
    void setup();
    void turn(Player attackingPlayer, Player defendingPlayer);
    bool validAttack(Player attackingPlayer, int row, char col);
    char attack(Player attackingPlayer, Player defendingPlayer, int row, char col);
    bool gameover();
    void play();

};
#endif
