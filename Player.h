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
    //Constructors
    Player();
    Player(int size);

    //Deconstructor
    ~Player();

    //Getters
    Board getVisibleBaord();
    Board getInvisibleBoard();
    int getNumberOfShips();
    int getShipCounter();
    Ship** getShips();

    //Setters
    //Notes: Use these functions if we construct
    //the Player class without passing a parameter
    void setNumberOfShips(int numberOfShips);
    void setShipCounter(int shipCounter);
    //Set ships if there is a shipCounter and number of ships
    void setShips(); 
    //Set ships by passing in an array of Ship
    void setShips(Ship** ships);
    void setVisibleBoard(Board visibleBoard&);
    void setInvsibleBoard(Board invisibleBoard&);

    //Main Functions
    //Set Up
    bool isValid(int startRow, int startCol, int endRow, int endCol, int size);
    void placeShip(Ship ship);
    void printSetup();

    //Game Play
    void view();
    void shipHealthBar();
    void sinkShip(int hitShip);
    void markFriendly(char strike, int row, int col);
    void markHostile(char strike, int row, int col);
};
#endif