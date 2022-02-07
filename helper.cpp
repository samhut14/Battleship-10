#include "helper.h"

helper::helper()
{

}

void helper::test()
{
    player = new Player(1);
    std::cout << player->getNumberOfShips() << "\n";
    std::cout << player->getShipCounter() << "\n";
    std::cout << player->getPrivateBoard()->at(0 , 0) << "\n";
    std::cout << player->getPublicBoard()->at(0 , 0) << "\n";

    std::cout << "\n";

    std::cout << player->startValid(0 , 0) << "\n";
    std::cout << player->startValid(0 , 0) << "\n";
    std::cout << player->startValid(-1 , 0) << "\n";
    std::cout << player->startValid(10 , 0) << "\n";
    std::cout << player->startValid(0 , -1) << "\n";
    std::cout << player->startValid(0 , 10) << "\n";

    std::cout << "\n";

    player->pathValid(0 , 1, 0, 1, 1);
    
    std::cout << player->getShips()[0]->getColumn(0) << "\n";
}