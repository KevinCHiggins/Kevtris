#include <sdl.h>
#include "draw.h"
#include "entities.h"
#include "shape.h"

void drawBlock(Coord position, SDL_Surface *block, SDL_Surface *screen)
{
    SDL_Rect temp;
    temp.x = (position.x*30);    //This should refer instead to a const
    temp.y = (position.y*30);
    temp.w = temp.h = 30;
    SDL_BlitSurface(block, 0, screen, &temp);
    return;
}

void wipeScreen(SDL_Surface *screen)
{
    SDL_Rect temp;
    temp.x=temp.y=0;
    temp.w=800;
    temp.h=600;
    Uint32 black = SDL_MapRGB((*screen).format, 0, 0, 0);
    SDL_FillRect(screen, &temp, black);
}

void drawShape(Shape shape, SDL_Surface *block, SDL_Surface *screen)
{
    Coord b1, b2, b3, b4;
    getCoords(shape, b1, b2, b3, b4);
    b1 = b1 + shape.position;
    b2 = b2 + shape.position;
    b3 = b3 + shape.position;
    b4 = b4 + shape.position;
    drawBlock(b1, block, screen);
    drawBlock(b2, block, screen);
    drawBlock(b3, block, screen);
    drawBlock(b4, block, screen);
    return;
}

void drawScore(int score, SDL_Surface *textSurface, SDL_Surface *screen, TTF_Font *gameFont)
{
    SDL_Rect temp;
    SDL_Color white = {255,255,255,0};
    char scoreString[6];
    scoreString[4]=48 + (score % 10);
    scoreString[3]=48 + ((score % 100)/10);
    scoreString[2]=48 + ((score % 1000)/100);
    scoreString[1]=48 + ((score % 10000)/1000);
    scoreString[0]=48 + ((score % 100000)/10000);
    scoreString[5]=0;   //Terminator
    textSurface = TTF_RenderText_Solid(gameFont, scoreString, white);  //Put text onto textSurface
    temp.x = (480);    //This should refer instead to a const
    temp.y = (80);
    temp.w = temp.h = 200;
    SDL_BlitSurface(textSurface, 0, screen, &temp);
    return;
}


