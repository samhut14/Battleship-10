#include "Game.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

Game::Game()
{
    player1 = nullptr;
    player2 = nullptr;
    totalXs = 0;
}

Game::~Game()
{
    delete player1;
    delete player2;
}
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

char Game::getChar()
{
    string temp = "";
    getline(cin, temp);
    while (temp.length() != 1)
    {
        cout << "Please enter a single character: ";
        getline(cin, temp);
    }
    return temp.at(0);
}

void Game::setup()
{
    cout << "\nWelcome to Battleship!\nBelow are the symbols you will see on the boards and what they mean:\n";
    cout << "S followed by a number represents a ship and its number\n";
    cout << "M means an attack has missed\nH means a ship was hit\nX means the ship in place is sunk\n\n";

    cout << "How many ships would you like to have this game? (1-5): ";
    numShips = 0;
    while (numShips < 1 || numShips > 5)
    {
        numShips = getInt();
        if (numShips < 1 || numShips > 5)
            cout << "Invalid choice.\nEnter number of ships: ";
    }

    player1 = new Player(numShips);
    player2 = new Player(numShips);

    cout << "Player 1's turn to set up:\n";
    setupPlayer(player1);
    clear();

    cout << "Player 2's turn to set up:\n";
    setupPlayer(player2);
    clear();
}

void Game::setupPlayer(Player *somePlayer)
{
    int startRow = -1, startCol = -1, endRow = -1, endCol = -1;
    char temp;

    while (true)
    {
        startRow = -1, startCol = -1, endRow = -1, endCol = -1;
        cout << "\nWhere would you like to place Ship 1? (1x1):\n";

        somePlayer->printSetup();

        cout << "Enter row: ";
        while (startRow < 1 || startRow > 10)
        {
            startRow = getInt();
            if (startRow < 1 || startRow > 10)
                cout << "Invalid choice.\nEnter row: ";
        }
        startRow--;

        cout << "Enter column: ";
        while (startCol < 0 || startCol > 9)
        {
            temp = getChar();
            startCol = temp - 65;

            if (startCol < 0 || startCol > 9)
                cout << "Invalid choice.\nEnter column: ";
        }

        if (!somePlayer->pathValid(startRow, startCol, startRow, startCol, 1))
            cout << "Invalid column. Start over.\n\n";
        else
            break;
    }

    for (int i = 1; i < numShips; i++)
    {
        while (true)
        {
            startRow = -1, startCol = -1, endRow = -1, endCol = -1;
            cout << "\nWhere would you like to place Ship " << i + 1 << "? (1x" << i + 1 << "):\n";

            somePlayer->printSetup();

            cout << "Enter starting row: ";
            while (startRow < 1 || startRow > 10)
            {
                startRow = getInt();
                if (startRow < 1 || startRow > 10)
                    cout << "Invalid choice.\nEnter starting row: ";
            }
            startRow--;

            cout << "Enter starting column: ";
            while (startCol < 0 || startCol > 9)
            {
                temp = getChar();
                startCol = temp - 65;

                if (startCol < 0 || startCol > 9)
                    cout << "Invalid choice.\nEnter starting column: ";
            }

            if (somePlayer->startValid(startRow, startCol))
            {
                if (i == 0)
                {
                    somePlayer->pathValid(startRow, startCol, startRow, startCol, 1);
                    break;
                }

                cout << "Enter ending row: ";
                while (endRow < 1 || endRow > 10)
                {
                    endRow = getInt();
                    if (endRow < 1 || endRow > 10)
                        cout << "Invalid choice.\nEnter ending row: ";
                }
                endRow--;

                cout << "Enter ending column: ";
                while (endCol < 0 || endCol > 9)
                {
                    temp = getChar();
                    endCol = temp - 65;

                    if (endCol < 0 || endCol > 9)
                        cout << "Invalid choice.\nEnter ending column: ";
                }

                if (!somePlayer->pathValid(startRow, startCol, endRow, endCol, i + 1))
                    cout << "Invalid ending position. Start over.\n\n";
                else
                    break;
            }

            else
                cout << "Invalid starting position. Start over.\n\n";
        }
    }

    somePlayer->printSetup();
}

void Game::clear()
{
    char temp = '\0';

    while (temp != 'c') 
    {
        cout << "Your turn has concluded. Please enter c to clear the screen for your opponent: ";
        temp = getChar(); //returns a valid character to be used
    }

    for (int i = 0; i < 50; i++) //clears the screen
        cout << '\n';

    cout << "The screen is now ready for your opponent. Please pass the computer to them.\n\n";
    temp = '\0';

    while (temp != 'c')
    {
        cout << "Enter c to confirm the start of your turn: ";
        temp = getChar(); //returns a valid character to be checked against
    }
}

void Game::play()
{
    currentPlayer = 2;
    setup(); 

    for (int i = 1; i <= numShips; i++) //tallies the total number of Xs needed to declare gameover
    {
        totalXs += i;
    }

    while (!gameover())
    {
        switch (currentPlayer) //alternates the current player during each iteration
        {
            case 1:
            {
                currentPlayer = 2;
                break;
             }
            case 2:
            {
                currentPlayer = 1;
                break;
            }
        }

        turn(currentPlayer);

        if (!gameover()) //only calls clear if gameover doesn't occur
        {
            clear();
        }
    }
    std::cout << "Player " << currentPlayer << " won!\n";
}

void Game::turn(int currentPlayer) //passes control over to the takeTurn function
{

    if (currentPlayer == 1)
    {
        std::cout << "Player 1's turn\n";
        takeTurn(player1, player2);
    }
    else
    {
        std::cout << "Player 2's turn\n";
        takeTurn(player2, player1);
    }
}

void Game::takeTurn(Player *currentPlayer, Player *otherPlayer)
{
    int row = -1;
    int col = -1;
    char temp = '\0';

    currentPlayer->view(); //prints the boards and ship health

    do //stuck in a loop until the player produces a valid attack location
    {
        row = -1;
        col = -1;

        while (!(row >= 0 && row < 10)) //Gets an attack row and only accepts it if it's within board
        {
            row = -1;
            std::cout << "Select attack row: ";
            row = getInt();
            row -= 1;
        }
        while (!(col >= 0 && col < 10)) //Gets an attack col and escapes the loop if the coordinate is inside the board region
        {
            col = -1;
            std::cout << "Select attack column: ";
            temp = getChar();
            col = (int(temp) - 65);
        }
    } while (!validAttack(currentPlayer, row, col)); //checks to see if the attack location is a spot that the player has already fired on

    attack(currentPlayer, otherPlayer, row, col); //actually figures out if it's a hit or miss and marks the boards
    currentPlayer->view(); //Prints the board again showing the attack
}

bool Game::validAttack(Player *attackingPlayer, int row, int col)
{
    if (attackingPlayer->getPublicBoard()->at(row, col) == "*") //checks the board that they are firing on to see if they have already attacked it
    {
        return (true);
    }
    else 
    {
        std::cout << "Invalid attack location. Enter a new attack coordinate.";
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
                if (player1->getPublicBoard()->at(i, j) == "X") //goes through player 1's firing board to see how many times sunk spots they have
                {
                    temp++;
                }
            }
        }

        if (temp == totalXs) // if the number of sunk spots on the firing board matches the total number of possible sunk spots, the game is over
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
                if (player2->getPublicBoard()->at(i, j) == "X")
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

void Game::attack(Player *attackingPlayer, Player *defendingPlayer, int row, int col)
{
    // if there is a hit, set to true
    bool isHit = false;

    // checks if attack location is a ship
    if (defendingPlayer->getPrivateBoard()->at(row, col)[0] == 'S')
    {
        isHit = true;
        // stores the id of ship to be passed into mark functions
        int hitship = defendingPlayer->getPrivateBoard()->at(row, col)[1] - 48;
        string *posArr = defendingPlayer->markPrivate("H", row, col, hitship, isHit);
        if (posArr)
        {
            attackingPlayer->markPrivateSunk(posArr, hitship);
        }
        else
        {
            attackingPlayer->markPublic("H", row, col);
        }
    }
    else
    {
        defendingPlayer->markPrivate("M", row, col, 0, isHit);
        attackingPlayer->markPublic("M", row, col);
    }
}
