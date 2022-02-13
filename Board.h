#ifndef BOARD_H
#define BOARD_H
#include <string>
using namespace std;
class Board
{
    private:
    //2d board array
    string** Boardarr;
    public:
    /*
     * @Pre: board is not constructed
     * @Post: constructs the board and intializes it to all *'s
     * @Return: none
    */
   Board();
   /*
     * @Pre: none
     * @Post: deletes the 2d board array
     * @Return: none
    */
   ~Board();
   /*
     * @Pre: none
     * @Post: gets the 2d board array pointer
     * @Return: the 2d board array pointer
    */
   string** getArr();
   /*
     * @Pre: none
     * @Post: Look for the specific row and column on the board.
     * @Return: return the string at the the specific row and column in the parameter. 
    */
   string at(int row, int col);
   /*
     * @Pre: none
     * @Post: takes in the mark, row and col, puts a mark in that spefic row and column on the board.
     * @Return: none
    */
   void setBoard(string mark, int row, int col);
};
#endif
