#include "Ship.h"
using namespace std;
Ship::Ship(int size, string* locationArr)
{
    m_size = size;
    m_life = size;
    posArr = locationArr;
    posArr = new string[m_size];
    for (int i = 0; i < m_size; i++) {
        posArr[i] = locationArr[i];
    }
}
//Ship::Ship() {}

Ship::~Ship()
{   
   delete[] posArr;    
}
void Ship::setAlive(bool alive)
{
    m_alive = alive;
}

int Ship::getSize()
{
    return(m_size);
}

int Ship::getLife()
{
    return m_life;
}
bool Ship::getAlive()
{
    return m_alive;
}
int Ship::getColumn(int index)
{
    return (posArr[index].at(1)-65);
}
int Ship::getRow(int index)
{
    return (posArr[index].at(0)-48);
}
string* Ship::getPositionArr()
{
   return posArr; 
}

bool Ship::loseLife() {
    return (--m_life == 0);
}
