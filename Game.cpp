#include "Game.h"

void Game::play()
{
    currentPlayer = 2;
    setup();
    
    for(int i=1; i <= numShips; i++)
    {
        totalXs += i;
    }

    while(!gameover())
    {
        switch(currentPlayer)
        {
            case 1: currentPlayer = 2;
            case 2: currentPlayer = 1;
        }

        turn(currentPlayer);
    }
    std::cout<<"Player "<< currentPlayer <<" won!";

}

void Game::turn(int currentPlayer)
{
    int row = 0;
    char col = '\0';
    char strike;

    if(currentPlayer == 1)
    {
        player1.view();

        do
        {
            while(row > 0 && row < 11)
            {
                std::cout<<"Please select which row you would like to attack:";
                std::cin>>row;
            }

            while(int(col) > 64 && int(col) < 91)
            {
                std::cout<<"Please select which column you would like to attack:";
                std::cin>>col;
            }
        } while(!validAttack(player1, row, col));

        strike = attack(player1, player2, row, col);
    }
    else
    {
        player2.view();

        do
        {
            while(row > 0 && row < 11)
            {
                std::cout<<"Please select which row you would like to attack:";
                std::cin>>row;
            }

            while(int(col) > 64 && int(col) < 91)
            {
                std::cout<<"Please select which column you would like to attack:";
                std::cin>>col;
            }
        } while(!validAttack(player2, row, col));

        strike = attack(player2, player1, row, col);
    }
}


bool Game::validAttack(Player attackingPlayer, int row, char col)
{
    if(attackingPlayer.getInvisibleBoard()[row-1][(int(col))-65] == "*") 
    {
        return(true);
    }  
    else
    {
        return(false);
    }
}