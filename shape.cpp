#include "entities.h"
#include "shape.h"
#include "collision.h"

void tryRotate(Shape &shape, bool *uncleared)
{
    Shape temp = shape;
    Coord b1, b2, b3, b4;
    switch(temp.id)     //Wrap around rotations after correct amount of rotations - 4, 2 or 1 depending on shape id
    {
        case T:
            if (temp.orientation<3) temp.orientation++; else temp.orientation=0;
            break;
        case L:
            if (temp.orientation<3) temp.orientation++; else temp.orientation=0;
            break;
        case R:
            if (temp.orientation<3) temp.orientation++; else temp.orientation=0;
            break;
        case I:
            if (temp.orientation<1) temp.orientation++; else temp.orientation=0;
            break;
        case S:
            if (temp.orientation<1) temp.orientation++; else temp.orientation=0;
            break;
        case Z:
            if (temp.orientation<1) temp.orientation++; else temp.orientation=0;
            break;
        case O:
            break;
    }
    getAbsoluteCoords(temp, b1,b2,b3,b4);

    if ((!isFilled(b1, uncleared)) && (!isFilled(b2, uncleared)) && (!isFilled(b3, uncleared)) && (!isFilled(b4, uncleared)))  //Gank
    {
        shape.orientation=temp.orientation;
    }
    return;
}

void tryMoveSideways(Shape &shape, bool left, bool *uncleared)
{
    Coord b1, b2, b3, b4;
    Shape temp = shape;
    if (left) temp.position.x -=1; else temp.position.x += 1; //Shift temporary shape into where our shape is trying to be
    getAbsoluteCoords(temp, b1,b2,b3,b4);


        if ((!isFilled(b1, uncleared)) && (!isFilled(b2, uncleared)) && (!isFilled(b3, uncleared)) && (!isFilled(b4, uncleared)))  //Gank
        {
            shape.position = temp.position;
        }


    return;
}

void tryMoveDownwards(Shape &shape, bool *uncleared)
{
    Coord b1, b2, b3, b4;
    Shape temp = shape;
    temp.position.y +=1; //Shift temporary shape into where our shape is trying to be
    getAbsoluteCoords(temp, b1,b2,b3,b4);


        if ((!isFilled(b1, uncleared)) && (!isFilled(b2, uncleared)) && (!isFilled(b3, uncleared)) && (!isFilled(b4, uncleared)))  //Gank
        {
            shape.position = temp.position;
        }
        else
        {
            shape.isDead=true;
        }


    return;
}
void transferBlocks(Shape &shape, bool *uncleared)
{
    Coord b1, b2, b3, b4;
    getAbsoluteCoords(shape, b1,b2,b3,b4);

    uncleared[b1.x + (b1.y*10)] = true;
    uncleared[b2.x + (b2.y*10)] = true;
    uncleared[b3.x + (b3.y*10)] = true;
    uncleared[b4.x + (b4.y*10)] = true;
    return;
}

void reset(Shape &shape, bool &gameOver, bool *uncleared)
{

    shape.id=(shapenames)(rand() % 7);         //TEST
    shape.position.x=5;
    shape.position.y=0;
    shape.orientation=0;
    shape.lastFellTime=0;
    shape.isDead=false;

    Coord b1, b2, b3, b4;
    getAbsoluteCoords(shape, b1,b2,b3,b4);


    if ((isFilled(b1, uncleared)) || (isFilled(b2, uncleared)) || (isFilled(b3, uncleared)) || (isFilled(b4, uncleared)))  //if there's no room for the new block
    {
        gameOver=true;
    }
    return;
}

void getAbsoluteCoords(Shape shape, Coord &b1, Coord &b2, Coord &b3, Coord &b4)
{
    Coord t1, t2, t3, t4;
    getCoords(shape, t1,t2,t3,t4);
    b1 = t1 + shape.position;
    b2 = t2 + shape.position;
    b3 = t3 + shape.position;
    b4 = t4 + shape.position;
    return;
}

void getCoords(Shape shape, Coord &b1, Coord &b2, Coord &b3, Coord &b4)
{
    switch (shape.id)
    {
        case T:
            switch (shape.orientation)
            {
                case 0:
                    b1.x=0; b1.y=1;
                    b2.x=1; b2.y=1;
                    b3.x=2; b3.y=1;
                    b4.x=1; b4.y=2;
                    break;
                case 1:
                    b1.x=1; b1.y=0;
                    b2.x=0; b2.y=1;
                    b3.x=1; b3.y=1;
                    b4.x=1; b4.y=2;
                    break;
                case 2:
                    b1.x=1; b1.y=0;
                    b2.x=0; b2.y=1;
                    b3.x=1; b3.y=1;
                    b4.x=2; b4.y=1;
                    break;
                case 3:
                    b1.x=1; b1.y=0;
                    b2.x=1; b2.y=1;
                    b3.x=2; b3.y=1;
                    b4.x=1; b4.y=2;
                break;
            }
            break;
        case L:
            switch (shape.orientation)
            {
                case 0:
                    b1.x=0; b1.y=1;
                    b2.x=1; b2.y=1;
                    b3.x=2; b3.y=1;
                    b4.x=0; b4.y=2;
                    break;
                case 1:
                    b1.x=0; b1.y=0;
                    b2.x=1; b2.y=0;
                    b3.x=1; b3.y=1;
                    b4.x=1; b4.y=2;
                    break;
                case 2:
                    b1.x=2; b1.y=0;
                    b2.x=0; b2.y=1;
                    b3.x=1; b3.y=1;
                    b4.x=2; b4.y=1;
                    break;
                case 3:
                    b1.x=1; b1.y=0;
                    b2.x=1; b2.y=1;
                    b3.x=1; b3.y=2;
                    b4.x=2; b4.y=2;
                break;
            }
            break;
        case R:
            switch (shape.orientation)
            {
                case 0:
                    b1.x=0; b1.y=1;
                    b2.x=1; b2.y=1;
                    b3.x=2; b3.y=1;
                    b4.x=2; b4.y=2;
                    break;
                case 1:
                    b1.x=1; b1.y=0;
                    b2.x=1; b2.y=1;
                    b3.x=0; b3.y=2;
                    b4.x=1; b4.y=2;
                    break;
                case 2:
                    b1.x=0; b1.y=0;
                    b2.x=0; b2.y=1;
                    b3.x=1; b3.y=1;
                    b4.x=2; b4.y=1;
                    break;
                case 3:
                    b1.x=1; b1.y=0;
                    b2.x=2; b2.y=0;
                    b3.x=1; b3.y=1;
                    b4.x=1; b4.y=2;
                break;
            }
            break;
        case I:
            switch (shape.orientation)
            {
                case 0:
                    b1.x=1; b1.y=0;
                    b2.x=1; b2.y=1;
                    b3.x=1; b3.y=2;
                    b4.x=1; b4.y=3;
                    break;
                case 1:
                    b1.x=0; b1.y=1;
                    b2.x=1; b2.y=1;
                    b3.x=2; b3.y=1;
                    b4.x=3; b4.y=1;
                    break;
            }
            break;
        case S:
            switch (shape.orientation)
            {
                case 0:
                    b1.x=1; b1.y=1;
                    b2.x=2; b2.y=1;
                    b3.x=0; b3.y=2;
                    b4.x=1; b4.y=2;
                    break;
                case 1:
                    b1.x=1; b1.y=0;
                    b2.x=1; b2.y=1;
                    b3.x=2; b3.y=1;
                    b4.x=2; b4.y=2;
                    break;
            }
            break;
        case Z:
            switch (shape.orientation)
            {
                case 0:
                    b1.x=0; b1.y=1;
                    b2.x=1; b2.y=1;
                    b3.x=1; b3.y=2;
                    b4.x=2; b4.y=2;
                    break;
                case 1:
                    b1.x=1; b1.y=0;
                    b2.x=0; b2.y=1;
                    b3.x=1; b3.y=1;
                    b4.x=0; b4.y=2;
                    break;
            }
            break;
        case O:
            b1.x=1; b1.y=1;
            b2.x=2; b2.y=1;
            b3.x=1; b3.y=2;
            b4.x=2; b4.y=2;
        break;
    }
    return;
}
