#include "Texture.h"

#include "graphics/Drawer.h"
#include "io/FileLoader.h"

Texture::Texture(std::string path) :
    iAsset(AS_TEXTURE)
{
    m_tex = FileLoader::LoadTexture(path);
    SDL_QueryTexture(m_tex,NULL,NULL,&m_rect.w,&m_rect.h);
}

void Texture::Render(int x, int y)
{
    SDL_Rect aux = m_rect;
    aux.x = x;
    aux.y = y;
    Drawer::renderTexture(m_tex,&aux);
}

void Texture::Render(Rect rect)
{
    SDL_Rect aux = rect.To_SDLRect();
    Drawer::renderTexture(m_tex,&aux);
}

void Texture::Scale(float w, float h)
{
   m_rect.w *= w;
   m_rect.h *= h;
}

Texture::Texture(SDL_Texture *tex) : iAsset(AS_TEXTURE)
{
    m_tex = tex;
    SDL_QueryTexture(m_tex,NULL,NULL,&m_rect.w,&m_rect.h);

}

SDL_Texture *Texture::setTexture( SDL_Texture* tex)
{
    SDL_DestroyTexture(m_tex);
    m_tex = tex;
    SDL_QueryTexture(m_tex,NULL,NULL,&m_rect.w,&m_rect.h);

}

Texture Texture::operator=(Texture &tex)
{
    m_rect = tex.m_rect;
    m_tex  = tex.m_tex;

    return *this;
}

Rect Texture::getRect() const
{
    Rect rect;
    rect.x = m_rect.x;
    rect.y = m_rect.y;
    rect.w = m_rect.w;
    rect.h = m_rect.h;
    return rect;
}

Texture::~Texture()
{
    SDL_DestroyTexture(m_tex);
}
