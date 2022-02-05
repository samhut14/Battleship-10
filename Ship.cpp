#include "Ship.h"

int Ship::getRow(int index)
{
    return (posArr[index].at(0) - 48);
}

int Ship::getCol(int index)
{
    return posArr[index].at(1) - 65;

Ship::Ship() {
}

//decreases life and returns true if lives == 0
bool Ship::loseLife() {
    return (--lives == 0);

}