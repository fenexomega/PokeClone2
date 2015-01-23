#ifndef TEXTURE
#define TEXTURE

#include <SDL2/SDL.h>
#include <iostream>

#include "physics/Rect.h"
#include "interfaces/iAsset.h"

class Texture : iAsset
{
private:
    SDL_Texture* m_tex;
    SDL_Rect m_rect;
    friend class Drawer;

public:
    Texture(std::string path);
//    Texture( int width,  int height,SDL_Texture *tex);
    void Render(int x, int y);
    void Render(Rect rect);
    void Render(Rect srcrect,Rect destrect);

    void Scale(float w,float h);
    Texture(SDL_Texture *tex);
    void setTexture(SDL_Texture *tex);
    Texture operator=(Texture &tex);
    Rect getRect() const;
    ~Texture();
};

#endif // TEXTURE



