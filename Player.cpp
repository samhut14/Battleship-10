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
 #include <string>
 
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

        //Finally, delete m_ships entirely
        delete[] m_ships;
    }

    //Next, deconstruct both visible and invisble board
    m_visibleBoard.~Board();
    m_invisibleBoard.~Board();
}
// I dont think u call destructors - Ahmni

//Sinks a player's ship
void Player::sinkShip(int hitship)
{
    //access the position array of the ship that got hit
    int* arr = m_ships[hitship-1].getPositionArr();
    // mark each palce ship is positioned with an X
    for (int i = 0; i < m_ships[hitship-1].getPosLength() - 1; i += 2) {
        m_visibleBoard.setBoard('X', arr[i], arr[i+1]);
    }
    std::cout << "Ship " << hitship << " was sunk! \n";
}
// only marks visible board, possible solution: make mark hostile a bool as well, pass into markfriendly
// how his position array handled?? will matter in implementation (tuple, or 1 by 1)


void Player::markHostile(char strike, int row, int col, int hitship, bool isHit) {
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


void Player::markFriendly(char strike, int row, int col) {
    std::string mark(std::string(1, strike));
    m_invisibleBoard.setBoard(mark, row, col);
}