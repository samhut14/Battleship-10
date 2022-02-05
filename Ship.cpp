#include "Ship.h"

Ship::Ship() {
}

bool Ship::loseLife() {
    return (--lives == 0);
}