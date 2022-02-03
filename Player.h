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
    //Represents the player's visible board
    //This the board the player used to place their ships
    Board m_visibleBoard;

    //Represent the player's invisible board
    //This board represent the player's view of their opponent board
    //The players uses this board to attach the opponent
    Board m_invisibleBoard;

    //Represent the number of ships that the player has
    int m_numberOfShips;

    //An array of Ship of size m_numberOfShips
    //Represents the Ships that the Player has
    Ship** m_ships;

    //Represents the number of ships that the player
    //currently has starting at m_numberOfShips 
    int m_shipCounter;

    public:
    //Constructors
    /**
	* @pre Player is not constructed
 	* @post Constructs Player without any parameter
 	* @param None
	* @return None
	*/
    Player();

    /**
	* @pre Player is not constructed
 	* @post Constructs Player by taking in
    *       the number of ships the player will have
 	* @param size, the number of ships that player has. Must
    *            be between 1 and 5.
    * @error Returns an runtime error if the number of ships
    *        being passed in is not between 1 and 5
	* @return None
	*/
    Player(int size);

    //Deconstructor
    /**
	* @pre Player is constructed
 	* @post Deconstructs Player
 	* @param None
	* @return None
	*/
    ~Player();

    //Getters
    /**
	* @pre Player is constructed
 	* @post Return the player's visible board
 	* @param None
	* @return Board m_visibleBoard, the player's visible board
	*/
    Board getVisibleBaord();

    /**
	* @pre Player is constructed
 	* @post Return the player's invisible board
 	* @param None
	* @return Board m_invisibleBoard, the player's invisiblbe board
	*/
    Board getInvisibleBoard();

    /**
	* @pre Player is constructed. number of ships is set up
 	* @post Gets the number of ships
 	* @param None
    *        Return an runtime error if the numberOfShips
    *        is not set up.
	* @return int m_numberOfShips, the number of ships 
    *         the player has. 
	*/
    int getNumberOfShips();

    /**
	* @pre Player is constructed. Ship counter is set up
 	* @post Returns shipCounter, the number of ships that the
    *       player currently has.
 	* @param None
    * @error Throws an runtime error is shipCounter is not set up. 
	* @return int m_shipCounter
	*/
    int getShipCounter();

    /**
	* @pre Player is constructed. m_Ships is constructed
 	* @post Returns the player's ships
 	* @param None
    * @error Throws an runtime error if m_Ships is not set up
	* @return Ship** m_Ships, the pointer to the array of ships
	*/
    Ship** getShips();

    //Setters
    //Notes: Use these functions if we construct
    //the Player class without passing a parameter
    /**
	* @pre Player is constructed
 	* @post Set the number of ships that the player has
 	* @param int numberOfShips, the number of ships the player has
	* @return None
	*/
    void setNumberOfShips(int numberOfShips);

    /**
	* @pre Player is constructed
 	* @post Set the number of ships that the player currently has 
 	* @param int shipCounter, the number of ships the player currenlty has
	* @return None
	*/
    void setShipCounter(int shipCounter);

    /**
	* @pre Player is constructed. Can be set if the m_numberOfShips
    *      is set
 	* @post Set up the Ships of the player using m_numberOfShips
 	* @param None
    * @error Throws an runtime error if m_numberOfShips is not set up
	* @return None
	*/
    void setShips(); 
    
    /**
	* @pre Player is constructed .
 	* @post Set up m_Ships by passing an array of ships
 	* @param Ship** ships, an array of Ships being using to
    *        set up ships
    * @error Throws an runtime error if the size of ships is not
    *        between 1 and 5
	* @return None
	*/
    void setShips(Ship** ships);

    /**
	* @pre Player is constructed. 
 	* @post Sets m_visibleBoard by passing in another Board
 	* @param Board visibleBoard, the Board being passed to 
    *        set up the Player's visible board
	* @return None
	*/
    void setVisibleBoard(Board visibleBoard&);

    /**
	* @pre Player is  constructed
 	* @post Sets m_invisibleBoard by passing in another Board
 	* @param Board invisibleBoard, the Board being passed to
    *        set up the Player's invisble board
	* @return None
	*/
    void setInvsibleBoard(Board invisibleBoard&);

    //Main Functions
    //Set Up
    bool isValid(int startRow, int startCol, int endRow, int endCol, int size);
    void placeShip(Ship ship);
    void printSetup();

    //Game Play
    /**
	* @pre Player is constructed. Can only be displayed during a player's turn
 	* @post Display's the player view of the game. This includes the player;s
    *       visible board, invisible board, their ships, and all their hits and misses
 	* @param None
	* @return None
	*/
    void view();

    /**
	* @pre Player is constructed. Can only be displayed during a player's turn
 	* @post Display the ship's health and whether the ship is sunked or not
 	* @param None
	* @return None
	*/
    void shipHealthBar();

    /**
	* @pre Player is constructed. Happens when a ship is attacked
 	* @post Constructs Player without any parameter
 	* @param None
	* @return None
	*/
    void sinkShip(int hitShip);
    void markFriendly(char strike, int row, int col);
    void markHostile(char strike, int row, int col);
};
#endif