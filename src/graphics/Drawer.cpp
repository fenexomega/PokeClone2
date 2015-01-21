#include "Drawer.h"

#include "graphics/Window.h"

#define RENDERER Window::getActiveRenderer()

Drawer::Drawer()
{

}

void Drawer::clearScreen(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    SDL_SetRenderDrawColor(Window::getActiveRenderer(),r,g,b,a);
    SDL_RenderClear(Window::getActiveRenderer());
}


void Drawer::drawLine(Color color,int x1, int y1, int x2, int y2)
{
    SDL_SetRenderDrawColor(Window::getActiveRenderer(),color.r,color.g,color.b,color.a);
    SDL_RenderDrawLine(Window::getActiveRenderer(),x1,y1,x2,y2);
}



void Drawer::drawRect(Color color, int x, int y, int w, int h)
{
    SDL_Rect rect = {x,y,w,h};
    SDL_SetRenderDrawColor(Window::getActiveRenderer(),color.r,color.g,color.b,color.a);
    SDL_RenderDrawRect(Window::getActiveRenderer(),&rect);
}

void Drawer::fillRect(Color color, int x, int y, int w, int h)
{
    SDL_Rect rect = {x,y,w,h};
    SDL_SetRenderDrawColor(Window::getActiveRenderer(),color.r,color.g,color.b,color.a);
    SDL_RenderFillRect(Window::getActiveRenderer(),&rect);
}

Drawer::~Drawer()
{

}

void Drawer::renderTexture(SDL_Texture *texture, SDL_Rect *rect)
{
   SDL_RenderCopy(RENDERER, texture, NULL, rect);

}

