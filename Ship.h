#ifndef SHIP_H
#define SHIP_H
#include <string>
using namespace std;
class Ship
{

private:
    //The size of the ship position array
    int m_size;
    //The life of the ship
    int m_life;
    //one-dimesional ship array
    string *posArr;

public:
    /*
     * @Pre: Ship is not constructed
     * @Post: Intializes the position array and sets it equal to the location array in the parameter
     * @Return: none
    */
    Ship(int Size, string *locationArr);
    /*
     * @Pre: Ship is not constructed
     * @Post: constructs ship without parameters
     * @Return: none
    */
    Ship();
    /*
     * @Pre: none
     * @Post: de-allocates the postion array from the heap.
     * @Return: none
    */
    ~Ship();
    /*
     * @Pre: none
     * @Post: gets size
     * @Return: returns size
    */
    int getSize();
    /*
     * @Pre: none
     * @Post: gets life
     * @Return: returns life
    */
    int getLife();
    /*
     * @Pre: none
     * @Post: decreases the ships life until it is zero
     * @Return: returns true when life is 0
    */
    bool loseLife();
    /*
     * @Pre: none
     * @Post: get the column at a specfic index in the array
     * @Return: returns column
    */
    int getColumn(int index);
    /*
     * @Pre: none
     * @Post: gets the row at a specfic index in the array
     * @Return: returns row
    */
    int getRow(int index);
    /*
     * @Pre: none
     * @Post: gets the pointer of the position array
     * @Return: returns the pointer of the position array
    */
    string *getPositionArr();
};
#endif
