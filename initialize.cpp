#include "initialize.h"

int initialize(SDL_Surface *screen, SDL_Surface *block)
{

    /*
    if (SDL_Init(SDL_INIT_VIDEO)==-1) return 1;
    if ((screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF))==0)   //Creat double-buffered surface
    {                                                                                           //in video card memory
        return 2;
    }

    SDL_Surface *temp;
    if((temp = SDL_LoadBMP("block.bmp")) == 0)     //Load sprite to a temporary surface
    {
        return 3;
    }

    block = SDL_DisplayFormat(temp);         //Put the adjusted version of block.bmp onto the block surface

    SDL_FreeSurface(temp);
        */
    return 0;

}
