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
 
 //Constructs Player without any parameters
 Player::Player()
 {
     //Set m_numberOfShips to be 0 to show that Ships will not be set up
     m_numberOfShips = 0;

     //Set m_shipCounter to be 0
     m_shipCounter = 0;

     //Set m_ships to be nullptr
     m_ships = nullptr; 
 }

//Deconstructs Player
Player::~Player()
{
    // Checks if the array of ships has a size
    // If m_ships is not set to nullptr
    if(m_ships != nullptr)
    {
        //Goes throug each ship of m_ships
        for(int i = 0; i < m_numberOfShips; i++)
        {
            //If a Ship at index i in m_ships is not nullptr
            if(m_ships[i] != nullptr)
            {
                //Deconstruct the ship
               delete m_ships[i];
            }
        }


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
// I dont think u call destructors - Ahmni

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
            arr[i].push_back(startCol + 65);

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
            arr[i].push_back(startCol + 65);

            startRow += temp;
        }
    }
    m_ships[m_shipCounter] = Ship(size, arr);
    placeShip(m_ships[m_shipCounter]);
    return true;

//Sinks a player's ship
void Player::sinkShip(int hitship)
{
    //access the position array of the ship that got hit
    int* arr = m_ships[hitship-1].getPositionArr();
    // mark each palce ship is positioned with an X
    for (int i = 0; i < m_ships[hitship-1].getPosLength(); i++) {
        m_visibleBoard.setBoard('X', arr[i][0], arr[i][1]-65);
    }
    std::cout << "Ship " << hitship << " was sunk! \n";
}
// only marks visible board, possible solution: make mark hostile a bool as well, pass into markfriendly
// how his position array handled?? will matter in implementation (tuple, or 1 by 1)


void Player::markHostile(string strike, int row, int col, int hitship, bool isHit) {
    // converts character into string
    std::string mark(std::string(1, strike));
    m_visibleBoard.setBoard(mark, row, col);
    if (isHit) {    
        // checks if ship is sunk
        if (m_ships[hitship-1].loseLife()) {
            sinkShip(hitship);
        } else {
            std::cout << "Ship " << hitship << " was hit \n";
        }
    } else {
        m_visibleBoard.setBoard(mark, row, col);
        std::cout << "Your attack missed! \n";
    }
    
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

        m_invisibleBoard.setBoard(symbol, row, col);
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

void Player::markFriendly(string strike, int row, int col) {
    std::string mark(std::string(1, strike));
    m_invisibleBoard.setBoard(mark, row, col);

}
