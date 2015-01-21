#ifndef COLOR_H
#define COLOR_H

#include "SDL2/SDL.h"

typedef struct color
{
    uint8_t r,g,b,a;
}Color;

#define COLOR_BLUE COLOR_BLUE = {0,0,255,255}

static const Color COLORRED = {255,0,0,255};
static const Color COLORBLUE = {0,0,255,255};
static const Color COLORGREEN = {0,255,0,255};
static const Color COLORWHITE = {255,255,255,255};
static const Color COLORBLACK = {0,0,0,255};



#endif // uSColor_H
