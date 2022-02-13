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
	 * @pre Player is constructed. m_Ships is constructed
	 * @post Returns the player's ships
	 * @param None
	 * @error Throws an runtime error if m_Ships is not set up
	 * @return Ship* m_Ships, the pointer to the array of ships
	 */
	Ship **getShips();

	// Main Functions
	// Set Up

	/*
	 * @pre row and col are not out of bounds
	 * @post checks if the position on the Private Board is valid to place a Ship
	 * @param int row and col represent the index at which to check
	 * @return false if invalid, true otherwise
	 */
	bool startValid(int row, int col);

	/*
	 * @pre starting and ending row and col are not out of bounds
	 * @post the path from the starting to the ending position is checked,
	 * if valid, a new Ship object is created in the array
	 * @param int startRow, startCol, endRow, endCol represent the indeces to check; int size is the size of the wanted Ship
	 * @return false if invalid, true otherwise
	 */
	bool pathValid(int startRow, int startCol, int endRow, int endCol, int size);

	/*
	 * @pre the parameter Ship was created in the correct array position
	 * @post the Ship is placed on the Private Board, and the Ship counter is incremented
	 * @param Ship *someShip is the Ship to place
	 * @return none
	 */
	void placeShip(Ship *someShip);

	/*
	 * @pre none
	 * @post the Private Board is printed appropriately
	 * @param none
	 * @return none
	 */
	void printPrivateBoard();

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
	 * @error Thorws an runtime error if hitShip is greater than m_numberOfShips, less than 0,
	 *	     or the ship is already sunked.
	 * @return None
	 */
	void sinkShip(int hitShip);

	/**

	 * @pre Player is constructed. Can only be used if the player is getting attacked
	 * @post Marks the player friendly's board, or the player
	 *		visible board
	 * @param char strike, the character that will mark the board, int row
	 *		 the row of the the strike, and int col, the column of the strike
	 * @error Throws an runtime error if the row and col are not valid or if strike
	 *		 is not a valid character
	 * @return None
	 */
	void markPublic(string strike, int row, int col);

	/**
	 * @pre Player is constructed. Can only be used if the player is attacking
	 * @post Marks the player visible board
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
