#ifndef RECT_H
#define RECT_H

#include <SDL2/SDL.h>
#include "math/Vector2D.h"

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

    inline Rect operator+(Vector2D vec)
    {
        Rect r(x + vec.x, y + vec.y, w,h);
        return r;
    }

    inline Rect& operator+=(Vector2D vec)
    {
        x += vec.x;
        y += vec.y;
        return *this;
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

static inline std::ostream& operator<<(std::ostream& ost,Rect r)
{
    return ost << "{ " << r.x << "," << r.y << "," << r.w << "," << r.h << " }";
}

#endif // RECT_H
