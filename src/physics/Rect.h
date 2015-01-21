#ifndef RECT_H
#define RECT_H

#include <SDL2/SDL.h>

class Rect
{
public:
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;
    Rect(int _x,int _y, int _w, int _h)
        : x(_x), y(_y), w(_w), h(_h)
    {

    }

    bool operator==(Rect rect)
    {
        return rect.x == x && rect.y == y && rect.w == w && rect.h == h;
    }

    SDL_Rect To_SDLRect()
    {
        SDL_Rect r = {x,y,w,h};
        return r;
    }

    Rect(){}
};

#endif // RECT_H
