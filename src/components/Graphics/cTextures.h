#ifndef CTEXTURES_H
#define CTEXTURES_H

#include <iostream>
#include "SDL2/SDL.h"
#include "systems/sysGraphics.h"

class cTextures
{
private:
    SDL_Texture *texture;
public:
    SDL_Rect rect;
    cTextures(std::string file);
    void setAlpha(const float a);
    void Render(int x, int y);
    void Render();
};

#endif // CTEXTURES_H
