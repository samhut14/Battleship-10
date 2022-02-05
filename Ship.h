#ifndef SHIP_H
#define SHIP_H

class Ship 
{
    private: 
    int lives;
    int* position;
    int poslength;
    int size;
    public:
    Ship();
    // makes live counter go down for ship, and check if needs to be sunk
    bool loseLife();
    int* getPositionArr();
    int getPosLength();
};

#endif
