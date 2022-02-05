#include "Board.h"
#include "Ship.cpp"
#include <string>
#include <iostream>
using namespace std;
Board::Board()
{
    Boardarr = new string*[10];
    for(int i = 0; i < 10; i++)
    {
        Boardarr[i] = new string[10];
    }
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            Boardarr[i][j] = "*";
        }
    }
    
}

void Board::setRow(int rw)
{
    rw= row;
}
void Board::setColumn(int cl)
{
    cl = col;
}
int Board::getRow()
{
    return row;
}
int Board::getColumn()
{
    return col;
}
string* Board::getArr()
{
    return Boardarr;
}



