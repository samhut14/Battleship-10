#ifndef SHIP_H
#define SHIP_H
#include <string>
using namespace std;
class Ship
{

private:
    int m_size;
    int m_life;
    string *posArr;

public:
    Ship(int Size, string *locationArr);
    Ship();
    ~Ship();
    int getSize();
    int getLife();
    bool loseLife();
    int getColumn(int index);
    int getRow(int index);
    string *getPositionArr();
};
#endif
