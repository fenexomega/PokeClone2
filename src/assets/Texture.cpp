#include "Texture.h"

#include "io/FileLoader.h"

#include "graphics/Window.h"

#include "util/Logger.h"

SDL_Texture *Texture::tex() const
{
    return m_tex;
}

void Texture::setTex(SDL_Texture *tex)
{
    m_tex = tex;
}

Uint32 Texture::pixelFormat() const
{
    return m_pixelFormat;
}

void Texture::setPixelFormat(const Uint32 &pixelFormat)
{
    m_pixelFormat = pixelFormat;
}

int Texture::acess() const
{
    return m_acess;
}

void Texture::setAcess(int acess)
{
    m_acess = acess;
}
Texture::Texture(std::string path) :
    iAsset(AS_TEXTURE)
{
    m_tex = FileLoader::LoadTexture(path);
    SDL_QueryTexture(m_tex,&m_pixelFormat,&m_acess,&m_rect.w,&m_rect.h);
}


void Texture::Scale(float w, float h)
{
   m_rect.w *= w;
   m_rect.h *= h;
}

Texture::Texture(Uint32 pf,int w, int h) : iAsset(AS_TEXTURE)
{
    m_tex = SDL_CreateTexture(Window::getActiveRenderer()
                              ,pf,
                              SDL_TEXTUREACCESS_TARGET,w,h);
    if(m_tex == NULL)
    {
        ERROR(SDL_GetError());
    }
    m_pixelFormat = pf;
    m_rect = {0,0,w,h};
}

Texture::Texture(SDL_Texture *tex) : iAsset(AS_TEXTURE)
{
    m_tex = tex;
    SDL_QueryTexture(m_tex,&m_pixelFormat,&m_acess,&m_rect.w,&m_rect.h);

}

void Texture::setTexture( SDL_Texture* tex)
{
    SDL_DestroyTexture(m_tex);
    m_tex = tex;
    SDL_QueryTexture(m_tex,&m_pixelFormat,&m_acess,&m_rect.w,&m_rect.h);
    m_rect.x = 0;
    m_rect.y = 0;

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
