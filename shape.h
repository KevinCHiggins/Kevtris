#ifndef SHAPE_H_
#define SHAPE_H_
#include "entities.h"

void getCoords(Shape shape, Coord &b1, Coord &b2, Coord &b3, Coord &b4);
void getAbsoluteCoords(Shape shape, Coord &b1, Coord &b2, Coord &b3, Coord &b4);
void tryRotate(Shape &shape, bool *uncleared);
void tryMoveSideways(Shape &shape, bool left, bool *uncleared);   //if left is not true, then the function will know to move right
void tryMoveDownwards(Shape &shape, bool *uncleared);
void transferBlocks(Shape &shape, bool *uncleared);
void reset(Shape &shape, bool &gameOver, bool *uncleared);
#endif

