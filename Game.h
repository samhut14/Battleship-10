#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Player.h"

class Game
{
private:
    int currentPlayer;
    int totalXs;
    int numShips;
    Player *player1;
    Player *player2;

public:
    Game();
    ~Game();
    void setup();
    void setupPlayer(Player *somePlayer);
    int getInt();
    void clear();
    void turn(int currentPlayer);
    void attack(Player *attackingPlayer, Player *defendingPlayer, int row, int col);
    bool validAttack(Player *attackingPlayer, int row, int col);
    bool gameover();
    void play();
};
#endif
