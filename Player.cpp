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
    //Checks if the array of ships has a size
    //If m_ships is not set to nullptr
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

//Sinks a player's ship
void sinkShip(int hitship)
{
    //First, we check if hitship
    //hitship is valid if it is less than or equal to the number of ships
    //and it is greater than 0
    //histship is also valid if we are not sunking a ship that is already sunk
    if(hitship <= 0 || hitship > m_numberOfShips)
    {
        //Throw an error, telling the user that the ship does not exist
        throw(std::runtime_error("Ship does not exist. You can only attack ship from 1 to 5."));
    }
    
    //Otherwise, continue the program
    //We are goinng to check if a ship is already sunked later

    //Next, we loop hitship times starting at 0
    for(int i = 0; i < hitship; i++)
    {
        //Next, we get the one of the position of the ship
        std::string position;

        //Next, create two integers that will store the row and column of the position
        int row;
        int col;

        //Next, check the length of position
        //If the length of position is two
        if(position.length() == 2)
        {
            //Set row to the first character - 48
            row = position[0] - 48;
        }
    }
}


