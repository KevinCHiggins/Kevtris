#include <sdl.h>
#include "input.h"

void gatherInput(SDL_Event event, bool &left, bool &right, bool &down, bool &rotate, bool &quit)
{
    //static bool keyrotate;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
            {
                if (event.key.keysym.sym==SDLK_LEFT) left=true;
                if (event.key.keysym.sym==SDLK_RIGHT) right=true;
                if (event.key.keysym.sym==SDLK_DOWN) down=true;
                if (event.key.keysym.sym==SDLK_UP) rotate=true;
                break;
            }
            case SDL_KEYUP:
            {
                if (event.key.keysym.sym==SDLK_LEFT) left=false;
                if (event.key.keysym.sym==SDLK_RIGHT) right=false;
                if (event.key.keysym.sym==SDLK_DOWN) down=false;
                //if (event.key.keysym.sym==SDLK_UP) rotate=true;
                break;
            }

            case SDL_QUIT:
            {
                quit=true;
            }
        }
    }

    return;
}

void waitForInput()
    {
        SDL_Event event;
        bool quitCommand = false;
        do
        {
        if (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_KEYDOWN:
                    quitCommand=true;
                    break;
                case SDL_KEYUP:
                    quitCommand=true;
                    break;
                case SDL_QUIT:
                    quitCommand=true;
                    break;
                }
            }

        }
        while (!quitCommand);
        return;
    }
/*
void resetInput(SDL_Event event, bool &left, bool &right, bool &down, bool &rotate)
{

    left=right=down=rotate=false;   //Turn off all input variables before checking if any of them are currently pressed
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
            {
                if (event.key.keysym.sym==SDLK_LEFT) left=true;
                if (event.key.keysym.sym==SDLK_RIGHT) right=true;
                if (event.key.keysym.sym==SDLK_DOWN) down=true;
                if (event.key.keysym.sym==SDLK_SPACE) rotate=true;
                break;
            }


        }
    }


    return;
}
    */
