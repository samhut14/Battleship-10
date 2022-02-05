#ifndef BOARD_H
#define BOARD_H
#include <string>
using namespace std;
class Board
{
    private:
    int row;
    int col;
    string** Boardarr;
    public:
   Board();
   ~Board();
   string** getArr();
   string at(int row, int col);
   void setBoard(string mark, int row, int col);
   //int Boardat(int row,int col); 
   //int Boardset(int row, int col, char element);
};
#endif
