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

void Drawer::Render(Texture *texture, Rect *rect)
{
    SDL_Rect sdlrect = rect->To_SDLRect();
   SDL_RenderCopy(RENDERER, texture->tex(), NULL, &sdlrect);

}

void Drawer::Render(Texture *texture, Rect *srcrect, Rect *destrect)
{
    SDL_Rect src = srcrect->To_SDLRect(), dest = destrect->To_SDLRect();
    SDL_RenderCopy(RENDERER, texture->tex(),&src,&dest);

}

void Drawer::Render(Texture *texture, int x, int y)
{
    SDL_Rect rect = texture->getRect().To_SDLRect();
    rect.x = x;
    rect.y = y;
    SDL_RenderCopy(RENDERER, texture->tex(), NULL, &rect);

}

void Drawer::Render(Texture *texture, Vector2D<int> vec)
{
    SDL_Rect rect = texture->getRect().To_SDLRect();
    rect.x = vec.x;
    rect.y = vec.y;
    SDL_RenderCopy(RENDERER, texture->tex(), NULL, &rect);
}

void Drawer::RenderTo(Texture *texture )
{
    if(texture == NULL)
        SDL_SetRenderTarget(RENDERER,NULL);
    else
        SDL_SetRenderTarget(RENDERER,texture->tex());
}

