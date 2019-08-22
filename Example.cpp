#include <stdlib.h>
#include <time.h>
#include <sdl.h>
#include <sdl_ttf.h>
#include "entities.h"
#include "surfaces.h"
#include "draw.h"
#include "input.h"
#include "shape.h"
#include "collision.h"

int main ( int argc, char *argv[] )
{

    SDL_Surface *screen=0;          //Surface that's actually drawn to screen... all pointers are initialised to 0
    SDL_Surface *block=0;           //Block sprite
    SDL_Surface *textSurface=0;
    SDL_Event event;
    bool field[2000];
    Shape shape;
    Coord fieldDrawCoords;  //Used to make calls to drawBlock when drawing field
    bool leftKeyPressed, rightKeyPressed, downKeyPressed, rotateKeyPressed, quitCommand;

    bool gameOver=false;
    leftKeyPressed=rightKeyPressed=downKeyPressed=rotateKeyPressed=quitCommand = false;
    int score=0;
    int linesCount=0; //Used to count up lines cleared, so the game know when to speed up the falling blocks

    srand (time(0));
    for (int i = 0; i<200; i++) field[i]=false; //Clear field

    Uint32 inputGatherTime, lastInputReaction; //Used to create a time window inputGatherTime ms long in which keypresses are gathered, and after which they are reset
    Uint32 fallTime;    //Time in ms between mandated falls of the tetrad
    inputGatherTime = 50;  //Reset input every 10th of a second (100ms)
    lastInputReaction=SDL_GetTicks();
    fallTime=500;

    if (SDL_Init(SDL_INIT_VIDEO)==-1) return 2;

    TTF_Init();

    TTF_Font *gameFont = TTF_OpenFont("jesaya free.ttf", 48);

    if ((screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF))==0)   //Creat double-buffered surface
    {                                                                                           //in video card memory
        return 3;
    }


    SDL_WM_SetCaption("Kevtris", "kevtris.ico");

        SDL_Surface *temp;
    if((temp = SDL_LoadBMP("block.bmp")) == 0)     //Load sprite to a temporary surface
    {
        return 4;
    }

    block = SDL_DisplayFormat(temp);         //Put the adjusted version of block.bmp onto the block surface

    reset(shape, gameOver, field);

    do
    {

        gatherInput(event, leftKeyPressed, rightKeyPressed, downKeyPressed, rotateKeyPressed, quitCommand);
        if (SDL_GetTicks()-lastInputReaction>inputGatherTime)  //if inputGatherTime has elapsed since lastInputReaction
        {   //Do movement

            if (rotateKeyPressed)
                {
                    tryRotate(shape, field);
                    rotateKeyPressed=false;
                }
            if (leftKeyPressed && (!rightKeyPressed))
            {
                tryMoveSideways(shape, 1, field);
            }
            else if (rightKeyPressed && (!leftKeyPressed))
            {
                tryMoveSideways(shape, 0, field);
            }
            if (((SDL_GetTicks()-shape.lastFellTime)>fallTime) || downKeyPressed)
            {
                tryMoveDownwards(shape, field);
                shape.lastFellTime=SDL_GetTicks();
            }
            lastInputReaction=SDL_GetTicks();
        }

        if (shape.isDead)
        {
            int i;
            transferBlocks(shape, field);
            i = clearFullRows(field);
            score += i;
            linesCount += i;
            if (linesCount>4)
            {
                fallTime = fallTime * 0.9;
                linesCount=0;
            }
            reset(shape, gameOver, field);

        }
        drawShape(shape, block, screen);

        for (int i=0; i<200; i++)
        {
            if (field[i])
            {
                fieldDrawCoords.x=(i%10);
                fieldDrawCoords.y=(i/10);
                drawBlock(fieldDrawCoords, block, screen);
            }
        }
        drawScore(score, textSurface, screen, gameFont);
        SDL_Flip(screen);
        wipeScreen(screen);

        if (gameOver)
        {
            quitCommand=true;
            waitForInput();
        }
    }
    while (quitCommand==false);

    TTF_CloseFont(gameFont);
    SDL_FreeSurface (block);
    SDL_FreeSurface (screen);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
