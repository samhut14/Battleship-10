/** -----------------------------------------------------------------------------
 *
 * @file  Player.cpp
 * @authors Amith Panuganti
 * Assignment:   EECS-448 Project #1
 * @brief This file impliment the methods of Player
 * @date 2/3/22
 *
 ---------------------------------------------------------------------------- **/
#include "Player.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Constructs Player without any parameters
Player::Player()
{
    // Set m_numberOfShips to be 0 to show that Ships will not be set up
    m_numberOfShips = 0;

    // Set m_shipCounter to be 0
    m_shipCounter = 0;

    // Set m_ships to be nullptr
    m_ships = nullptr;
}

Player::Player(int size)
{
    m_numberOfShips = size;
    m_ships = new Ship[m_numberOfShips];

    m_shipCounter = 0;
}

// Deconstructs Player
Player::~Player()
{
    // If m_ships is not set to nullptr
    if (m_ships != nullptr)
        delete[] m_ships;
}

// Sinks a player's ship
void sinkShip(int hitship)
{
    // First, we check if hitship
    // hitship is valid if it is less than or equal to the number of ships
    // and it is greater than 0
    // histship is also valid if we are not sunking a ship that is already sunk
    if (hitship <= 0 || hitship > m_numberOfShips)
    {
        // Throw an error, telling the user that the ship does not exist
        throw(std::runtime_error("Ship does not exist. You can only attack ship from 1 to 5."));
    }

    // Otherwise, continue the program
    // We are goning to check if a ship is already sunked later

    // Next, we loop hitship times starting at 0
    for (int i = 0; i < hitship; i++)
    {
        // Next, we get the one of the position of the ship
        String position;

        // Aftwards, get the row and column of each
    }
}

// Setup functions:

bool Player::startValid(int row, int col)
{
    return (m_invisibleBoard.at(row, col) == "*");
}

bool Player::pathValid(int startRow, int startCol, int endRow, int endCol, int size)
{
    int temp;
    string arr[5];

    if ((startRow == endRow) && (startCol != endCol))
    {
        if (abs(endCol - startCol) == size)
        {
            if (startCol > endCol)
                temp = -1;
            else
                temp = 1;

            goto traverseCol;
        }
        else
            return false;
    }

    else if ((startRow != endRow) && (startCol == endCol))
    {
        if (abs(endRow - startRow) == size)
        {
            if (startRow > endRow)
                temp = -1;
            else
                temp = 1;

            goto traverseRow;
        }
        else
            return false;
    }

    return false;
traverseCol:
    for (int i = 0; i < size; i++)
    {
        if (m_invisibleBoard.at(startRow, startCol) != "*")
            return false;
        else
        {
            arr[i] = to_string(startRow);
            arr[i].push_back(startCol - 65);

            startCol += temp;
        }
    }
    m_ships[m_shipCounter] = Ship(size, arr);
    placeShip(m_ships[m_shipCounter]);
    return true;

traverseRow:
    for (int i = 0; i < size; i++)
    {
        if (m_invisibleBoard.at(startRow, startCol) != "*")
            return false;
        else
        {
            arr[i] = to_string(startRow);
            arr[i].push_back(startCol - 65);

            startRow += temp;
        }
    }
    m_ships[m_shipCounter] = Ship(size, arr);
    placeShip(m_ships[m_shipCounter]);
    return true;
}

void Player::placeShip(Ship someShip)
{
    // Add ship to array through operator overloading??
    int row, col;
    string symbol = "S" + to_string(someShip.getSize());

    for (int i = 0; i < someShip.getSize(); i++)
    {
        row = someShip.getRow(i);
        col = someShip.getCol(i);

        m_invisibleBoard.set(row, col, symbol);
    }

    m_shipCounter++;
}

void Player::printSetup()
{
    cout << "  A B C D E E F G I J\n\n";
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << "  ";
        for (int j = 0; j < 10; j++)
            cout << m_invisibleBoard.at(i, j) << " ";

        cout << endl;
    }
}