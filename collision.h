#ifndef COLLISION_H_
#define COLLISION_H_
#include "entities.h"
#include "shape.h"
bool isFilled(Coord position, bool *uncleared);  //Checks if a particular position in the 2D array of uncleared blocks is empty
int clearFullRows(bool *uncleared);
#endif
