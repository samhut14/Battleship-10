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

//Print the healthbar for each ship
void Player::shipHealthBar()
{
    //Example dislay
    // Ships Health:
    // 1x1: 5     1x2: Sunked     1x3: 4  

    //Firstly, tell the user that we are printing their ships helath
    std::cout << " Ships Health:\n ";

    //Next, we are goning to put everything in one line for now
    //Loop for each ship the player hass
    for(int i = 0; i < m_numberOfShips; i++)
    {
        //Print out the Ship with size 1x(i+1
        std::cout << "1x" + (i+1) + ": ";

        //Next, check if the ship is stil alive
        //TODO: Get functions for returing life and alive status
        //If the ship is still alive
        if(true)
        {
            //Print the ships life
        }
        //Otherwise, if the ship is not alived
        else
        {
            //Display that the ship is not alive anymore
            std::cout << "Sunked     ";
        }
    }

    //Add the end of the loop, print a new line
    std::cout << "\n";

    //TODO: Add all functions that will get status the 
    //The amount health a ship has
    //Add any more style changes if needed
}

//Print the player's view during gameplay
void Player::view()
{
    //Example view 
    //     A   B   C   D
    // 1  S1  S2   X   X
    // 2   *   *   *   *
    // 3   *   *   *   *
    // 4   *   *   *   *

    //Firstly, we need to print the player's view of their oponent's Board
    //Then, tell the user what board we are printing out
    std::cout << " Opponent's Board:\n\n";

    //Next, print the columns of the board into one line
    std::cout << "     A   B   C   D   E   F   G   H   I   J\n";
    
    //Next, for loop 10 times for each row of the board
    for(int i = 0; i < 10; i++)
    {
        //Print the row number of the board 
        std::cout << " " + (i+1) + "   ";

        //Goes throug each string of the row
        for(int j = 0; j < 10; j++)
        {
            //Print the string at row i and column j
            std::cout << m_invisibleBoard.at(i, j) + "   ";
        }

        //Print a new line to end the row
        std::cout << "\n";
    }

    //Print a new line
    std::cout << "\n";

    //Next, we print the player's view of their board
    //Tell the user that we are printing out their board
    std::cout << " Your Board:\n\n";

    //Next, print the cloumns of the board into one line
     std::cout << "     A   B   C   D   E   F   G   H   I   J\n";
     //Next, for loop 10 times for each row of the board
    for(int i = 0; i < 10; i++)
    {
        //Print the row number of the board 
        std::cout << " " + (i+1) + "  ";

        //Goes through each string of the row
        for(int j = 0; j < 10; j++)
        {
            //Get the string at row i and column j
            std::string position = m_visibleBoard.at(i, j);

            //Next, check the length of position
            //If the length of the position is two
            if(position.length() == 2)
            {
                //Print the position
                std::cout << position + "  ";
            }
            //Otherwiie, if the the length of the position is 1
            else
            {
                //Add a space before printing the position
                std::cout << " " + position + "  ";
            }
        }

        //Print a new line to end the row
        std::cout << "\n";
    }

    //Print a new line
    std::cout << "\n";

    //Next, print the ship's healthbar
    shipHealthBar();

    //Print a new line
    std::cout << "\n";

    //TODO: Change Board Functions if needed
}

//Get the visible board
Board Player::getVisibleBoard()
{
    //Return m_visibleBoard
    return m_visibleBoard;
}

//Get the invisible board
Board Player::getInvisibleBoard()
{
    //Return m_invisibleBoard
    return m_invisibleBoard;
}

//Get the ship counter
int Player::getShipCounter()
{
    //Return m_shipCounter
    return m_shipCounter;
}

//Get the number of ships
int Player::getNumberOfShips()
{
    //Return m_numberOfShips
    return m_numberOfShips;
}

//Get the Player's Ships
Ship** Player::getShips()
{
    //Return m_ships
    return m_ships;
}