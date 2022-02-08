/** -----------------------------------------------------------------------------
 *
 * @file  Player.cpp
 * @authors Amith Panuganti
 * Assignment:   EECS-448 Project #1
 * @brief This file impliment the methods of Player
 * @date 2/4/22
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

    m_publicBoard = nullptr;
    m_privateBoard = nullptr;
}

Player::Player(int size)
{
    m_numberOfShips = size;
    m_ships = new Ship[m_numberOfShips];

    m_publicBoard = new Board();
    m_privateBoard = new Board();

    m_shipCounter = 0;
}

// Deconstructs Player
Player::~Player()
{
    // If m_ships is not set to nullptr
    if (m_ships != nullptr)
        delete[] m_ships;
}

// Setup functions:

bool Player::startValid(int row, int col)
{
    if (row < 0 || row > 9 || col < 0 || col > 9)
        return false;

    return (m_privateBoard->at(row, col) == "*");
}

bool Player::pathValid(int startRow, int startCol, int endRow, int endCol, int size)
{
    int temp;
    string arr[5];

    if ((startRow == endRow) && (startCol != endCol))
    {
        if (abs(endCol - startCol) == size - 1)
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
        if (abs(endRow - startRow) == size - 1)
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
    // FOLLOWING IS TEMP:
    else if ((startRow == endRow) && (startCol == endCol) && (size == 1))
    {
        arr[0] = to_string(startRow);
        arr[0].push_back(startCol + 65);

        m_ships[m_shipCounter] = Ship(size, arr);
        placeShip(m_ships[m_shipCounter]);
        return true;
    }
    // END OF TEMP

    return false;

traverseCol:
    for (int i = 0; i <= size - 1; i++)
    {
        if (m_privateBoard->at(startRow, startCol) != "*")
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
    for (int i = 0; i <= size - 1; i++)
    {
        if (m_privateBoard->at(startRow, startCol) != "*")
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
}

// Sinks a player's ship
void Player::sinkShip(int hitship)
{
    // access the position array of the ship that got hit
    string *arr = m_ships[hitship - 1].getPositionArr();
    // mark each palce ship is positioned with an X
    for (int i = 0; i < m_ships[hitship - 1].getSize(); i++)
    {
        cout << arr[i] << endl;
        cout << m_ships[i].getSize() << "";
    }
    // CODE ONLY WORKS WHEN I PRENT THIS OUT????? probably has to do with pointers maybe idk
    for (int i = 0; i < m_ships[hitship - 1].getSize(); i++)
    {
        // cout << arr[i].at(0) - 48 <<  arr[i].at(1) - 65 << endl;
        m_privateBoard->setBoard("X", arr[i].at(0) - 48, arr[i].at(1) - 65);
    }
    std::cout << "Ship " << hitship << " was sunk! \n";
}

void Player::markPrivateSunk(string *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        // cout << arr[i].at(0) - 48 << arr[i].at(1) - 65 << endl;
        m_publicBoard->setBoard("X", arr[i].at(0) - 48, arr[i].at(1) - 65);
    }
}

string *Player::markPrivate(string strike, int row, int col, int hitship, bool isHit)
{
    // converts character into string
    if (isHit)
    {
        // checks if ship is sunk
        if (m_ships[hitship - 1].loseLife())
        {
            sinkShip(hitship);
            return m_ships[hitship - 1].getPositionArr();
        }
        else
        {
            m_privateBoard->setBoard(strike, row, col);
            std::cout << "Ship " << hitship << " was hit \n";
        }
    }
    else
    {
        m_privateBoard->setBoard(strike, row, col);
        std::cout << "Your attack missed! \n";
    }
    return {};
}

void Player::placeShip(Ship &someShip)
{
    int row, col;
    string symbol = "S" + to_string(someShip.getSize());
    for (int i = 0; i < someShip.getSize(); i++)
    {
        row = someShip.getRow(i);
        col = someShip.getColumn(i);

        m_privateBoard->setBoard(symbol, row, col);
    }

    m_shipCounter++;
}

void Player::printSetup()
{
    cout << "Here is your current board:\n\n";
    cout << "\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\n\n";
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << "\t";
        for (int j = 0; j < 10; j++)
            cout << m_privateBoard->at(i, j) << "\t";

        cout << endl;
    }
}

// Print the healthbar for each ship
void Player::shipHealthBar()
{
    // Example dislay
    //  Ships Health:
    //  1x1: 5     1x2: Sunked     1x3: 4

    // Firstly, tell the user that we are printing their ships helath
    std::cout << " Ships Health:\n ";

    // Next, we are goning to put everything in one line for now
    // Loop for each ship the player hass
    for (int i = 0; i < m_numberOfShips; i++)
    {
        // Print out the Ship with size 1x(i+1
        std::cout << "1x" << (i + 1) << ": ";

        // Next, check if the ship is stil alive
        // TODO: Get functions for returing life and alive status
        // If the ship is still alive
        if (m_ships[i].getAlive() == true)
        {
            // Print the ships life
            std::cout << m_ships[i].getLife() << "     ";
        }
        // Otherwise, if the ship is not alived
        else
        {
            // Display that the ship is not alive anymore
            std::cout << "Sunked     ";
        }
    }

    // Add the end of the loop, print a new line
    std::cout << "\n";

    // TODO: Add all functions that will get status the
    // The amount health a ship has
    // Add any more style changes if needed
}

// Print the player's view during gameplay
void Player::view()
{
    // Example view
    //      A   B   C   D
    //  1  S1  S2   X   X
    //  2   *   *   *   *
    //  3   *   *   *   *
    //  4   *   *   *   *

    // Firstly, we need to print the player's view of their oponent's Board
    // Then, tell the user what board we are printing out
    std::cout << " Opponent's Board:\n\n";

    // Next, print the columns of the board into one line
    std::cout << "\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\n\n";

    // Next, for loop 10 times for each row of the board
    for (int i = 0; i < 10; i++)
    {
        // Print the row number of the board
        std::cout << i + 1 << "\t";

        // Goes throug each string of the row
        for (int j = 0; j < 10; j++)
        {
            // Print the string at row i and column j
            std::cout << m_publicBoard->at(i, j) << "\t";
        }

        // Print a new line to end the row
        std::cout << "\n";
    }

    // Print a new line
    std::cout << "\n";

    // Next, we print the player's view of their board
    // Tell the user that we are printing out their board
    std::cout << " Your Board:\n\n";

    // Next, print the cloumns of the board into one line
    std::cout << "\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\n\n";
    // Next, for loop 10 times for each row of the board
    for (int i = 0; i < 10; i++)
    {
        // Print the row number of the board
        std::cout << i + 1 << "\t";

        // Goes through each string of the row
        for (int j = 0; j < 10; j++)
        {
            // Print the string at row i and column j
            std::cout << m_privateBoard->at(i, j) << "\t";
        }

        // Print a new line to end the row
        std::cout << "\n";
    }

    // Print a new line
    std::cout << "\n";

    // Next, print the ship's healthbar
    shipHealthBar();

    // Print a new line
    std::cout << "\n";

    // TODO: Change Board Functions if needed
}

// Get the visible board
Board *Player::getPublicBoard()
{
    // Return m_publicBoard
    return m_publicBoard;
}

// Get the invisible board
Board *Player::getPrivateBoard()
{
    // Return m_privateBoard
    return m_privateBoard;
}

void Player::markPublic(string strike, int row, int col)
{
    m_publicBoard->setBoard(strike, row, col);
}

// Get the ship counter
int Player::getShipCounter()
{
    // Return m_shipCounter
    return m_shipCounter;
}

// Get the number of ships
int Player::getNumberOfShips()
{
    // Return m_numberOfShips
    return m_numberOfShips;
}

// Get the Player's Ships
Ship *Player::getShips()
{
    // Return m_ships
    return m_ships;
}
