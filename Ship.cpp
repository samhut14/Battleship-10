#include "Ship.h"
using namespace std;
Ship::Ship(int size, string* locationArr)
{
    _size = size;
    posArr = locationArr;
    posArr = new string[_size];
    for (int i = 0; i < _size; i++) {
        posArr[i] = locationArr[i];
    }
}
Ship::Ship()
{
}
Ship::~Ship()
{   
   delete[] posArr;    
}
void Ship::setAlive(bool a)
{
    a = alive;
}
int Ship::getLife()
{
    return life;
}
bool Ship::getAlive()
{
    return alive;
}
int Ship::getColumn(int index)
{
    return (posArr[index].at(1)-65);
}
int Ship::getRow(int index)
{
    return (posArr[index].at(0)-48);
}
string* Ship::getPositonArr()
{
   return posArr; 
}