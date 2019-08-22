#ifndef ENTITIES_H_
#define ENTITIES_H_
#include <sdl.h>


enum shapenames {T,L,R,I,S,Z,O};
class Coord
{
    public:
    Coord operator+(Coord op2);
    int x, y;
};
struct Shape
{
    shapenames id;
    int orientation;
    Uint32 lastFellTime;    //Time since last downwards movement
    Coord position;
    bool isDead;
};

#endif
