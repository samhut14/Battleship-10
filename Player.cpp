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

//Sinks a player's ship
void sinkShip(int hitship)
{
    //First, we check if hitship
    //hitship is valid if it is less than or equal to the number of ships
    //and it is greater than 0
    //histship is also valid if we are not sunking a ship that is already sunk
    //We also need to check if the ship is not alive before sinking it
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
            //Set row to the first character - 49
            row = (int)position[0] - 49;

            //Next,set the columen to be the second character - 65
            col = (int)position[1] - 65;
        }
        //Otherwise, if the length of position is three
        else if(position.length() == 3)
        {
            //Set row to be 9 because if the length of position is three
            //Then the row number must be 10
            //Example: 10A
            row = 9;

            //Next, set the column of position be the third character - 65
            col = (int)position[2] - 65;
        }

        //Next, check the position of the ship on the visible board 
        //Using row and col. We are doing this to make sure that 
        //the ship is not sunked. 
        //If the ship is already sunked
        if(m_visibleBoard.at(row, col) == "X")
        {
            //End the function
            //Immediately tell the user that the ship is already sunked
            throw(std::runtime_error("The ship is already sunked."));
        }

        //Otherwise, set the ship at position row, col to be X to represent
        //The ship being sunked
        m_visibleBoard.set(row, col, "X");
    }

    //Leave for now
    //Come back to print message about ship getting sinked
}

//Marks the player's invisible board
void Player:markFriendly(std::string strike, int row, int col)
{
    //Firstly, we need to check if row and col are valid and strike
    //is a valid character
    //If row is less than 0 or greater than 9
    if(row < 0 || row > 9)
    {
        //Throw an runtime error telling the user that row is invalid
        throw(std::runtime_error("Row is invalid. Must be between 0 and 9"));
    }
    //Otherwise, if col is less than 0 or less than 9
    else if(col < 0 || col > 9)
    {
        //Throw an runtime error tellling the user that col is invalid
        throw(std::runtime_error("Col is invalid. Must be between 0 and 9"));
    }
    //Otherwise, if strike is not H or M
    else if(strike != "H" && strike != "M")
    {
        //Throw an runtime error telling the user that strike in invalid
        throw(std::runtime_error("Strike is invalid. Must be either H or M"));
    }
    //Otherwise, if there isn't an asterik at the position (row, col)
    else if(m_invisibleBoard.at(row, col) != "*")
    {
        //Tell the user that that strike already happend at the position
        throw(std::runtime_error("You already mark the board at position row,col. You can only mark position with *"));
    }

    //Otherwise, continue the program
    //Set the string at row,col in the player's invisble board to be strike
    m_invisibleBoard.set(row, col, strike);
}


