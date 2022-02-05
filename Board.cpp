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
string** Board::getArr()
{
    return Boardarr;
}

string Board::at(int row, int col) {
    return Boardarr[row][col];
}

void Board::setBoard(string mark, int row, int col) {
    Boardarr[row][col] = mark;
}



