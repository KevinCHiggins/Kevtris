#ifndef INPUT_H_
#define INPUT_H_

void gatherInput(SDL_Event event, bool &left, bool &right, bool &down, bool &rotate, bool &quit);
void waitForInput();
//void resetInput(SDL_Event event, bool &left, bool &right, bool &down, bool &rotate);
#endif
