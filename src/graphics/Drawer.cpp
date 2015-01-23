#include "Drawer.h"

#include "graphics/Window.h"

#define RENDERER Window::getActiveRenderer()

Drawer::Drawer()
{

}

void Drawer::clearScreen(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    SDL_SetRenderDrawColor(RENDERER,r,g,b,a);
    SDL_RenderClear(RENDERER);
}


void Drawer::drawLine(Color color,int x1, int y1, int x2, int y2)
{
    SDL_SetRenderDrawColor(RENDERER,color.r,color.g,color.b,color.a);
    SDL_RenderDrawLine(RENDERER,x1,y1,x2,y2);
}



void Drawer::drawRect(Color color, int x, int y, int w, int h)
{
    SDL_Rect rect = {x,y,w,h};
    SDL_SetRenderDrawColor(RENDERER,color.r,color.g,color.b,color.a);
    SDL_RenderDrawRect(RENDERER,&rect);
}

void Drawer::fillRect(Color color, int x, int y, int w, int h)
{
    SDL_Rect rect = {x,y,w,h};
    SDL_SetRenderDrawColor(RENDERER,color.r,color.g,color.b,color.a);
    SDL_RenderFillRect(RENDERER,&rect);
}

Drawer::~Drawer()
{

}

void Drawer::renderTexture(SDL_Texture *texture, SDL_Rect *rect)
{
   SDL_RenderCopy(RENDERER, texture, NULL, rect);

}

void Drawer::renderTexture(SDL_Texture *texture, SDL_Rect *srcrect, SDL_Rect *destrect)
{
    SDL_RenderCopy(RENDERER, texture,srcrect,destrect);

}

