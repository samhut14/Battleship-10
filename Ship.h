#ifndef SHIP_H
#define SHIP_H
#include <string>
using namespace std;
class Ship
{
    private:
    int _size;
    int life;
    bool alive;
    string* posArr;
    public:
    Ship(int Size, string* locationArr);
    Ship();
    ~Ship();
    void setAlive(bool a);
    int getSize();
    int getLife();
    bool getAlive();
    bool loselife(int row, int col);
    int getColumn(int index);
    int getRow(int index);  
    string* getPositonArr();

};
#endif
