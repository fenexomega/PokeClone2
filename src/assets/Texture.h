#ifndef TEXTURE
#define TEXTURE

#include <SDL2/SDL.h>
#include <iostream>

#include "physics/Rect.h"
#include "interfaces/iAsset.h"

class Texture : public iAsset
{
private:
    SDL_Texture *m_tex;
    SDL_Rect m_rect;
    friend class Drawer;
    Uint32 m_pixelFormat;
    int m_acess;
public:
    Texture(int w, int h);
    Texture(SDL_Texture *tex);
    Texture operator=(Texture &tex);
    ~Texture();

    Rect getRect() const;

    void Scale(float w,float h);
    void setTexture(SDL_Texture *tex);
    SDL_Texture *tex() const;
    void setTex(SDL_Texture *tex);
    Uint32 pixelFormat() const;
    void setPixelFormat(const Uint32 &pixelFormat);
    int acess() const;
    void setAcess(int acess);
};

#endif // TEXTURE



