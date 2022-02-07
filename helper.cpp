#include "helper.h"

helper::helper()
{

}

void helper::test()
{
    //Create a new player with size 1
    player = new Player(1);

    //Getter
    std::cout << player->getNumberOfShips() << "\n";
    std::cout << player->getShipCounter() << "\n";
    std::cout << player->getPrivateBoard()->at(0 , 0) << "\n";
    std::cout << player->getPublicBoard()->at(0 , 0) << "\n";

    std::cout << "\n";

    //Check if start Valid is working properly
    std::cout << player->startValid(0 , 0) << "\n";
    std::cout << player->startValid(0 , 0) << "\n";
    std::cout << player->startValid(-1 , 0) << "\n";
    std::cout << player->startValid(10 , 0) << "\n";
    std::cout << player->startValid(0 , -1) << "\n";
    std::cout << player->startValid(0 , 10) << "\n";

    std::cout << "\n";

    //Use pathValid to create a 1x1 ship
    player->pathValid(0 , 1, 0, 1, 1);
    std::cout << player->getShips()[0]->getLife() << "\n";
    std::cout << player->getShips()[0]->getPositionArr()[0] << "\n";
    std::cout << player->getShips()[0]->getRow(0) << "\n";
    std::cout << player->getShips()[0]->getColumn(0) << "\n";
}