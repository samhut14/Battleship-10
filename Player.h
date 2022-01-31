/** -----------------------------------------------------------------------------
 *
 * @file  Player.h
 * @authors Amith Panuganti 
 * Assignment:   EECS-448 Project #1 
 * @brief This file contains the methods and variables of the Player class
 *        The Player plays Battleship by setting up their board, attacking the
 *        other's player board, getting attacked, and either winning or losing
 * @date 1/31/21
 *	
 ---------------------------------------------------------------------------- **/
#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"
#include "Ship.h"
#include <iostream>
#include <string>

class Player
{
    private:
    Board m_visibleBoard;
    Board m_invisibleBoard;
    int m_numberOfShips;
    Ship** m_ships;
    int m_shipCounter;

    public:
    Player();
    Player(int size);
    bool isValid(int startRow, int startCol, int endRow, int endCol, int size);
    void placeShip(Ship ship);
    void view();
    void printSetup();
    void shipHealthBar();
    void sinkShip(int hitShip);
    void markFriendly(char strike, int row, int col);
    void markHostile(char strike, int row, int col);
};
#endif