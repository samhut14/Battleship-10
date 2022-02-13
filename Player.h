/** -----------------------------------------------------------------------------
 *
 * @file  Player.h
 * @authors Amith Panuganti, Jasem Ali, Ahmni Pang-Johnson
 * Assignment:   EECS-448 Project #1
 * @brief This file contains the methods and variables of the Player class
 *        The Player plays Battleship by setting up their board, attacking the
 *        other's player board, getting attacked, and either winning or losing
 * @date 2/12/22
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
	// Represents the player's visible board
	// This the board the player used to place their ships
	Board *m_publicBoard;

	// Represent the player's invisible board
	// This board represent the player's view of their opponent board
	// The players uses this board to attach the opponent
	Board *m_privateBoard;

	// Represent the number of ships that the player has
	int m_numberOfShips;

	// An array of Ship of size m_numberOfShips
	// Represents the Ships that the Player has
	Ship **m_ships;

	// Represents the number of ships that the player
	// currently has starting at m_numberOfShips
	int m_shipCounter;

public:
	// Constructors
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

	// Deconstructor
	/**
	 * @pre Player is constructed
	 * @post Deconstructs Player
	 * @param None
	 * @return None
	 */
	~Player();

	// Getters
	/**
	 * @pre Player is constructed
	 * @post Return the player's visible board
	 * @param None
	 * @return Board m_publicBoard, the player's visible board
	 */
	Board *getPublicBoard();

	/**
	 * @pre Player is constructed
	 * @post Return the player's invisible board
	 * @param None
	 * @return Board m_privateBoard, the player's invisiblbe board
	 */
	Board *getPrivateBoard();

	/**
<<<<<<< HEAD
=======
	 * @pre Player is constructed. number of ships is set up
	 * @post Gets the number of ships
	 * @param None
	 * @return int m_numberOfShips, the number of ships
	 *         the player has.
	 */
	int getNumberOfShips();

	/**
	 * @pre Player is constructed. Ship counter is set up
	 * @post Returns shipCounter, the number of ships that the
	 *       player currently has.
	 * @param None
	 * @return int m_shipCounter
	 */
	int getShipCounter();

	/**
>>>>>>> documentation
	 * @pre Player is constructed. m_Ships is constructed
	 * @post Returns the player's ships
	 * @param None
	 * @return Ship** m_Ships, the pointer to the array of ships
	 */
	Ship **getShips();

	// Main Functions
	// Set Up
	bool startValid(int row, int col);
	bool pathValid(int startRow, int startCol, int endRow, int endCol, int size);
	void placeShip(Ship *someShip);
	void printSetup();

	// Game Play
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
	 * @post Attacks one of the player's ships and check if the ship is sunked or not.
	 * @param int hitShip, the ship that is hit
	 * @return None
	 */
	void sinkShip(int hitShip);

	/**

	 * @pre Player is constructed. Can only be used if the player is getting attacked
	 * @post Marks the player friendly's board, or the player
	 *		visible board
	 * @param char strike, the character that will mark the board, int row
	 *		 the row of the the strike, and int col, the column of the strike
	 * @return None
	 */
	void markPublic(string strike, int row, int col);

	/**
	 * @pre Player is constructed. Can only be used if the player is attacking
	 * @post Marks the player invisible board
	 * @param std::string strike, the character that will mark the board, int row
	 *		 the row of the the strike, and int col, the column of the strike
	 * @error Throws an runtime error if the row and col are not valid or if strike
	 *		 is not a valid character
	 * @return None
	 */
	string *markPrivate(string strike, int row, int col, int hitship, bool isHit);

	void markPublicSunk(string *posArr, int size);
};
#endif
