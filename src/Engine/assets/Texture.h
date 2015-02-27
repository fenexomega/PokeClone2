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

    //Escalaciona a textura
    void Scale(float w,float h);


    //getters
    Uint32 pixelFormat() const;
    SDL_Texture *tex() const;
    int acess() const;

    //setters
    void setTexture(SDL_Texture *tex); 
    void setTex(SDL_Texture *tex);
    void setPixelFormat(const Uint32 &pixelFormat);
    void setAcess(int acess);
};

#endif // TEXTURE



