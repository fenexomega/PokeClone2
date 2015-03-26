#include "Drawer.h"

#include "graphics/Window.h"
#include "assets/Texture.h"
#include "physics/Rect.h"
#include "assets/Font.h"
#include <SDL2/SDL_ttf.h>
#include "util/Logger.h"

#define RENDERER Window::getActiveRenderer()

Drawer::Drawer()
{

}

void Drawer::clearScreen(unsigned char r, unsigned char g,
                         unsigned char b, unsigned char a)
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

void Drawer::drawRect(Color color, Rect _rect)
{
    SDL_Rect rect = _rect.To_SDLRect();
    SDL_SetRenderDrawColor(RENDERER,color.r,color.g,color.b,color.a);
    SDL_RenderDrawRect(RENDERER,&rect);
}

void Drawer::fillRect(Color color, int x, int y, int w, int h)
{
    SDL_Rect rect = {x,y,w,h};
    SDL_SetRenderDrawColor(RENDERER,color.r,color.g,color.b,color.a);
    SDL_RenderFillRect(RENDERER,&rect);
}

void Drawer::fillRect(Color color, Rect _rect)
{
    SDL_Rect rect = _rect.To_SDLRect();
    SDL_SetRenderDrawColor(RENDERER,color.r,color.g,color.b,color.a);
    SDL_RenderFillRect(RENDERER,&rect);
}

void Drawer::setColor(Color color)
{

}

Drawer::~Drawer()
{

}

void Drawer::Render(const std::shared_ptr<Texture>texture,
                    Rect *const rect)
{
    SDL_Rect&& sdlrect = rect->To_SDLRect();
   SDL_RenderCopy(RENDERER, texture->tex(), NULL, &sdlrect);

}

void Drawer::Render(const std::shared_ptr<Texture> texture,
                    Rect *const srcrect, Rect *const destrect)
{
    SDL_Rect&& src = srcrect->To_SDLRect(), && dest = destrect->To_SDLRect();
    SDL_RenderCopy(RENDERER, texture->tex(),&src,&dest);

}

void Drawer::Render(const std::shared_ptr<Texture>texture,
                    const int x,const int y)
{
    SDL_Rect&& rect = texture->getRect().To_SDLRect();
    rect.x = x;
    rect.y = y;
    SDL_RenderCopy(RENDERER, texture->tex(), NULL, &rect);

}

void Drawer::Render(const std::shared_ptr<Texture>texture,
                    const Vector2D vec)
{
    SDL_Rect&& rect = texture->getRect().To_SDLRect();
    rect.x = vec.x;
    rect.y = vec.y;
    SDL_RenderCopy(RENDERER, texture->tex(), NULL, &rect);
}

void Drawer::Render(std::shared_ptr<Texture> texture, const int x, const int y,
                    float angle,const Vector2D center, int offsetx, int offsety)
{
    SDL_Rect&& srcrect = texture->getRect().To_SDLRect();
    SDL_Rect&& destrect = texture->getRect().To_SDLRect();
    SDL_Point&& centerP = {center.x,center.y};
    srcrect.x = destrect.x = x;
    srcrect.y = destrect.y = y;

    destrect.x += offsetx;
    destrect.y += offsety;
    SDL_RenderCopyEx(RENDERER, texture->tex(), &srcrect, &destrect,angle,&centerP,SDL_FLIP_NONE);
}

void Drawer::RenderTo(std::shared_ptr<Texture>texture )
{
    if(texture == NULL)
        SDL_SetRenderTarget(RENDERER,NULL);
    else
        SDL_SetRenderTarget(RENDERER,texture->tex());
}

void Drawer::RenderText(shared_ptr<Font> font, std::string text, int x, int y,
                        Color color,  Uint32 lineWrap,short align )
{
   shared_ptr<Texture> tex = font->getTexture(text,color,lineWrap);
   int ax = 0;
   switch(align)
   {
   case CENTER:
       ax = tex->getRect().x/2;break;
   case RIGHT:
       ax = tex->getRect().x;break;
   case LEFT:
       ax = 0; break;
   default:
      throw std::runtime_error
               ("Invalid Align value! (value = "
                + TOSTR(align) + ")");



   }

   Render(tex,x+ax,y);
}

