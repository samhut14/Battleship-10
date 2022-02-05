#ifndef SHIP_H
#define SHIP_H
#include <string>
using namespace std;
class Ship
{
    private:
    int column;
    int row;
    int size;
    int life;
    bool alive;
    string* posArr;
    public:
    Ship(int Size, string* locationArr);
    Ship();
    ~Ship();
    void setLife(int l);
    void setSize(int s);
    void setAlive(bool a);
    int getSize();
    int getLife();
    bool getAlive();
    bool loselife(int row, int col);
    void setColumn(int c);
    void setRow(int r);
    int getColumn(int index);
    int getRow(int index);  
};
#endif
