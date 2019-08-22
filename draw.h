#ifndef DRAW_H_
#define DRAW_H_
#include <sdl.h>
#include <sdl_ttf.h>
#include "entities.h"

void drawShape(Shape shape, SDL_Surface *block, SDL_Surface *screen);
void drawBlock(Coord position, SDL_Surface *block, SDL_Surface *screen);
void drawScore(int score, SDL_Surface *textSurface, SDL_Surface *screen, TTF_Font *gameFont);
void wipeScreen(SDL_Surface *screen);
#endif
