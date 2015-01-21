#include "cTextures.h"

cTextures::cTextures(std::string file)
{
//    texture = sysGraphics::loadTexture(file);
    int w,h;
    SDL_QueryTexture(texture,NULL,NULL,&w,&h);
    SDL_Rect rect = {0,0,w,h};
    this->rect = rect;
}

void cTextures::setAlpha(const float a )
{
    SDL_SetTextureAlphaMod(texture,255*a);
}

void cTextures::Render(int x, int y)
{
    rect.x = x;
    rect.y = y;
    sysGraphics::renderTexture(texture,rect);
}

void cTextures::Render()
{
    sysGraphics::renderTexture(texture,rect);
}
