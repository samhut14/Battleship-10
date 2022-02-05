#ifndef GAME.H
#define GAME .H
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
    void setupPlayer(Player somePlayer);
    int getInt();
    void turn(int currentPlayer);
    bool attack(Player attackingPlayer, Player defendingPlayer, int row, int col);
    bool validAttack(Player attackingPlayer, int row, int col);
    bool gameover();
    void play();
};
#endif
