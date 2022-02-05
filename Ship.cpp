#include "Ship.h"
using namespace std;
Ship::Ship(int Size, string* locationArr)
{
    Size = size;
    posArr = locationArr;
    posArr = nullptr;
    for(int i = 0; i <= size; i++)
    {
       for (int j = 0; i <=  size; i++)
       {
           posArr[i][j];
       }
       
    }
}
Ship::Ship()
{
}
Ship::~Ship()
{
    for (int i = 0; i <= size; i++)
    {
        delete[] posArr;
    }
    
}
void Ship::setLife(int l)
{
    l = life;
}
void Ship::setSize(int s)
{
    s = size;
}
void Ship::setAlive(bool a)
{
    a = alive;
}
int Ship::getLife()
{
    return life;
}
int Ship::getSize()
{
    return size;
}
bool Ship::getAlive()
{
    return alive;
}
bool Ship::loselife(int row, int col)
{
   for (int i = 0; i <= size; i++)
   {
       for (int j = 0; j <= size; i++)
       {
           if(posArr[row][col] == 'S')
           {
               life--;
               return true; 
           }
           else
           {
               return false;
           }
       }
       
   }
   return true;
   
}
void Ship::setColumn(int c)
{
    c = column;
}
void Ship::setRow(int r)
{
    r = row;
}
int Ship::getColumn(int index)
{
    return (posArr[index].at(1)-65);
}
int Ship::getRow(int index)
{
    return (posArr[index].at(1)-48);
}