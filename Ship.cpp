#include "Ship.h"

Ship::Ship() {
}

//decreases life and returns true if lives == 0
bool Ship::loseLife() {
    return (--lives == 0);
}