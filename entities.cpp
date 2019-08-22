#include "entities.h"

Coord Coord::operator+(Coord op2)
{
    Coord temp;
    temp.x = x + op2.x;
    temp.y = y + op2.y;
    return temp;
}
