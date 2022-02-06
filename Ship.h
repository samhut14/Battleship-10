#ifndef SHIP_H
#define SHIP_H
#include <string>
using namespace std;
class Ship
{
private:
    int m_size;
    int m_life;
    bool m_alive;
    string *posArr;

public:
    Ship(int Size, string *locationArr);
    Ship()
    {
        // Intentionally left blank
    }
    ~Ship();
    void setAlive(bool a);
    int getSize();
    int getLife();
    bool getAlive();
    bool loseLife();
    int getColumn(int index);
    int getRow(int index);
    string *getPositionArr();
};
#endif
