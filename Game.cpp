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
    int col = 0;
    char temp = '\0';
    char strike;

    if(currentPlayer == 1)
    {
        player1.view();

        do
        {
            while(row >= 0 && row < 10)
            {
                std::cout<<"Please select which row you would like to attack:";
                std::cin>>row;
                row -= 1;
            }

            while(col >= 0 && col < 10)
            {
                std::cout<<"Please select which column you would like to attack:";
                std::cin>>temp;
                col = (int(temp) - 65);
            }
        } while(!validAttack(player1, row, col));

        strike = attack(player1, player2, row, col);
    }
    else
    {
        player2.view();

        do
        {
            while(row >= 0 && row < 10)
            {
                std::cout<<"Please select which row you would like to attack:";
                std::cin>>row;
                row--;
            }

             while(col >= 0 && col < 10)
            {
                std::cout<<"Please select which column you would like to attack:";
                std::cin>>temp;
                col = (int(temp) - 65);
            }
        } while(!validAttack(player2, row, col));

        strike = attack(player2, player1, row, col);
    }
}


bool Game::validAttack(Player attackingPlayer, int row, int col)
{
    if(attackingPlayer.getInvisibleBoard().at(row, col) == "*") 
    {
        return(true);
    }  
    else
    {
        return(false);
    }
}

bool Game::gameover()
{
    int temp = 0;

    if(currentPlayer == 1)
    {
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                if(player1.getInvisibleBoard().at(i,j) == "X")
                {
                    temp++;
                }
            }
        }

        if(temp == totalXs)
        {
            return(true);
        }
    }
    else
    {
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                if(player2.getInvisibleBoard().at(i,j) == "X")
                {
                    temp++;
                }
            }
        }

        if(temp == totalXs)
        {
            return(true);
        }
    }

    return(false);
}