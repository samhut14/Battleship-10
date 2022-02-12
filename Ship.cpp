#include "Ship.h"
#include <iostream>
using namespace std;
Ship::Ship(int size, string *locationArr)
{
    m_size = size;
    m_life = size;
    posArr = new string[m_size];
    for (int i = 0; i < m_size; i++)
    {
        posArr[i] = locationArr[i];
    }
}
Ship::Ship()
{
    posArr = nullptr;
}

Ship::~Ship()
{
    delete[] posArr;
}

int Ship::getSize()
{
    return (m_size);
}

int Ship::getLife()
{
    return m_life;
}

int Ship::getColumn(int index)
{
    return (posArr[index].at(1) - 65);
}
int Ship::getRow(int index)
{
    return (posArr[index].at(0) - 48);
}
string *Ship::getPositionArr()
{
    return posArr;
}

bool Ship::loseLife()
{
    return (--m_life == 0);
}
