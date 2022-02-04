#include "Game.h"

void Game::play()
{
    setup();

    while(!gameover())
    {
        turn(player1, player2);
        
        if(gameover())
        {
            std::cout<<"Player 1 won!\n";
            break;
        }

        turn(player2, player1);

        if(gameover())
        {
            std::cout<<"Player 2 won!\n";
        }
    }

}

bool Game::validAttack(Player attackingPlayer, Player defendingPlayer, int row, char col)
{
    
}

void Game::turn(Player attackingPlayer, Player defendingPlayer)
{
    int row = 0;
    char col = '\0';

    while(!validAttack(attackingPlayer, row, col))
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
    }

    attack(attackingPlayer, defendingPlayer, row, col);
}

