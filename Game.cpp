#include "Game.h"
#include <iostream>
#include <limits>
using namespace std;

int Game::getInt()
{
    int n = 0;
    cin >> n;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter an integer: ";
        cin >> n;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return n;
}
void Game::setup()
{
    cout << "Welcome to Battleship!\nBelow are the symbols you will see on the boards and what they mean:\n";
    cout << "S followed by a number represents a ship and its number\n";
    cout << "M means an attack has missed\nH means a ship was hit\nX means the ship in place is sunk\n\n";

    cout << "How many ships would you like to have this game? (1-5): ";
    numShips = 0;
    while (numShips < 1 || numShips > 5)
    {
        numShips = getInt();
        if (numShips < 1 || numShips > 5)
            cout << "Invalid choice.\n";
    }

    player1 = Player(numShips);
    player2 = Player(numShips);

    cout << "Player 1's turn to set up:\n";
    setupPlayer(player1);

    clear();

    cout << "Player 2's turn to set up:\n";
    setupPlayer(player2);

    clear();
}

void Game::setupPlayer(Player somePlayer)
{
    for (int i = 0; i < numShips; i++)
    {
        cout << "Here is your current board:\n\n";
        somePlayer.printSetup();

        cout << "Where would you like to place Ship " << i + 1 << "?:";
        int startRow = -1, startCol = -1, endRow = -1, endCol = -1;
        char temp;

        while (!somePlayer.pathValid(startRow, startCol, endRow, endCol, i + 1))
        {
            startRow = -1, startCol = -1, endRow = -1, endCol = -1;

            cout << "Enter the starting row: ";
            while (startRow < 1 || startRow > 10)
            {
                startRow = getInt();
                if (startRow < 1 || startRow > 10)
                    cout << "Invalid choice.";
            }
            startRow--;

            cout << "Enter the starting column: ";
            while (startCol < 0 || startCol > 9)
            {
                cin >> temp;
                startCol = temp - 65;

                if (startCol < 0 || startCol > 9)
                    cout << "Invalid choice.";
            }

            // Starting position is valid

            if (somePlayer.startValid(startRow, startCol))
            {
                cout << "Enter the ending row: ";
                while (endRow < 1 || endRow > 10)
                {
                    endRow = getInt();
                    if (endRow < 1 || endRow > 10)
                        cout << "Invalid choice.";
                }
                endRow--;

                cout << "Enter the ending column: ";
                while (endCol < 0 || endCol > 9)
                {
                    cin >> temp;
                    endCol = temp - 65;

                    if (endCol < 0 || endCol > 9)
                        cout << "Invalid choice.";
                }

                if (!somePlayer.pathValid(startRow, startCol, endRow, endCol, i + 1))
                    cout << "Invalid ending position. Start over.\n\n";
            }

            else
                cout << "Invalid starting position. Start over.\n\n";
        }
    }
}

void Game::clear()
{   
    bool turnOver = true;
    char temp = '\0';

    while (turnOver)
    {
       std::cout<<"Your turn has now concluded. Please pass the computer to your opponent. Once that is done, type c for complete.";
       std::cin>> temp;

       if(temp == 'c')
       {
           turnOver = false;
       }
    }

    for(int i=0; i<30; i++)
    {
        std::cout<<'\n';
    }
    
    
}

void Game::play()
{
    currentPlayer = 2;
    setup();

    for (int i = 1; i <= numShips; i++)
    {
        totalXs += i;
    }

    while (!gameover())
    {
        switch (currentPlayer)
        {
        case 1:
            currentPlayer = 2;
        case 2:
            currentPlayer = 1;
        }

        turn(currentPlayer);
        if(!gameover())
        {
            clear();
        }
    }
    std::cout << "Player " << currentPlayer << " won!";
}

void Game::turn(int currentPlayer)
{
    int row = 0;
    int col = 0;
    char temp = '\0';

    if (currentPlayer == 1)
    {
        player1.view();

        do
        {
            while (row >= 0 && row < 10)
            {
                std::cout << "Please select which row you would like to attack:";
                row = getInt();
                row -= 1;
            }

            while (col >= 0 && col < 10)
            {
                std::cout << "Please select which column you would like to attack:";
                std::cin >> temp;
                col = (int(temp) - 65);
            }
        } while (!validAttack(player1, row, col));

        attack(player1, player2, row, col);
    }
    else
    {
        player2.view();

        do
        {
            while (row >= 0 && row < 10)
            {
                std::cout << "Please select which row you would like to attack:";
                std::cin >> row;
                row--;
            }

            while (col >= 0 && col < 10)
            {
                std::cout << "Please select which column you would like to attack:";
                std::cin >> temp;
                col = (int(temp) - 65);
            }
        } while (!validAttack(player2, row, col));

        attack(player2, player1, row, col);
    }
}

bool Game::validAttack(Player attackingPlayer, int row, int col)
{
    if (attackingPlayer.getInvisibleBoard().at(row, col) == "*")
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

bool Game::gameover()
{
    int temp = 0;

    if (currentPlayer == 1)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (player1.getInvisibleBoard().at(i, j) == "X")
                {
                    temp++;
                }
            }
        }

        if (temp == totalXs)
        {
            return (true);
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (player2.getInvisibleBoard().at(i, j) == "X")
                {
                    temp++;
                }
            }
        }

        if (temp == totalXs)
        {
            return (true);
        }
    }

    return (false);
}

void Game::attack(Player attackingPlayer, Player defendingPlayer, int row, int col) {
    // if there is a hit, set to true
    bool isHit = false;
  
        //checks if attack location is a ship
    if (((defendingPlayer.getVisibleBoard()).at(row,col))[0] == "S") {
        isHit = true;
        //stores the id of ship to be passed into mark functions
        int hitship = defendingPlayer.getVisibleBoard().at(row,col)[1];
        attackingPlayer.markFriendly('h', row, col);
        defendingPlayer.markHostile('h', row, col, hitship, isHit);
    }
    else {
        attackingPlayer.markFriendly('m', row, col);
        defendingPlayer.markHostile('m', row, col, 0, isHit);
    }
}

