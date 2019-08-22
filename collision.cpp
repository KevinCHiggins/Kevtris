#include "collision.h"

bool isFilled(Coord position, bool *uncleared)
{


    if (position.x<0 || position.x>9) return true;       //If block is beyond confines of field
    if (position.y>19) return true;
    return (uncleared[position.x + (position.y*10)]);

}

int clearFullRows(bool *uncleared)
{
    int rowsCleared = 0;
    int i = 190;    //Start checking from end of field;
    bool blocksInThisRow, fullRow;
    do
    {
        blocksInThisRow=false;  //Assume no blocks before testing
        fullRow=true;   //Assume it's a full row before testing
        for(int j=0; j<10; j++)
        {
            if (uncleared[i+j]) blocksInThisRow=true; else fullRow=false;
        }
        if (fullRow)
        {
            rowsCleared += 1;
            int k = i;              //Copy i's value so we can work up from it
            for (; k>9; k-=10)        //All rows from i up to the top of the field
            {
                for(int j=0; j<10; j++)
                uncleared[k+j]=uncleared[(k-10)+j];  // shift row above into row k
            }
            for (int j=0; j<10; j++) uncleared[j] = 0;  //Clear the very top row, which wasn't part of the shifting because it doesn't copy data from a row above
        }
        else
        {
            i-=10;    //if this row WASN'T found full and then cleared, move up to the next one
        }
    }
    while (blocksInThisRow && i>0); //if we've got up into empty rows or gone past the highest row, stop checking them
    return rowsCleared;
}
