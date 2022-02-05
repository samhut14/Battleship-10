#include "Board.h"
#include "Ship.cpp"
#include <string>
#include <iostream>
using namespace std;
Board::Board(int r, int c, string** B_arr)
{
    Boardarr = B_arr;
    r = row;
    c = col;
    string** Boardarr = nullptr;
    Boardarr = new string*[row];
    for(int i = 0; i < row; i++)
    {
        Boardarr[i] = new string[col];
    }
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            Boardarr[i][j] = "?";
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



