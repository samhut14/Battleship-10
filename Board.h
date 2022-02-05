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
   void setRow(int rw);
   void setColumn(int cl);
   int getRow();
   int getColumn();
   string* getArr();
   //int Boardat(int row,int col); 
   //int Boardset(int row, int col, char element);
};
#endif
