#ifndef GAME.H
#define GAME.H
#include <iostream>
#include "Player.h"

class Game
{
    private:
    int currentPlayer;
    int totalXs;
    int numShips;
    Player player1;
    Player player2;

    public:
    void setup();
    void turn(int currentPlayer);
    char attack(Player attackingPlayer, Player defendingPlayer, int row, char col);
    bool validAttack(Player attackingPlayer, int row, char col);
    bool gameover();
    void play();

};
#endif
