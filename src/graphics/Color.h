#ifndef COLOR_H
#define COLOR_H

#include <SDL2/SDL.h>

typedef struct color
{
    Uint8 r,g,b,a;

    SDL_Color toSDLColor()
    {
        SDL_Color color = {r,g,b,a};
        return color;
    }

    color(Uint8 _r, Uint8 _g , Uint8 _b , Uint8 _a)
        :  r(_r),g(_g),b(_b),a(_a) {}
}Color;

#define COLOR_BLUE COLOR_BLUE = {0,0,255,255}

static const Color COLORRED = {255,0,0,255};
static const Color COLORBLUE = {0,0,255,255};
static const Color COLORGREEN = {0,255,0,255};
static const Color COLORWHITE = {255,255,255,255};
static const Color COLORBLACK = {0,0,0,255};



#endif // uSColor_H
