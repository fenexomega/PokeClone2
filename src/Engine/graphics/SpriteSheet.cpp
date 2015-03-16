#include "SpriteSheet.h"

#include "graphics/Drawer.h"

#include "io/FileLoader.h"

unsigned int SpriteSheet::getFrames() const
{
    return frames;
}



Vector2D SpriteSheet::getSz() const
{
    return sz;
}



Rect SpriteSheet::getFramerect() const
{
    return framerect;
}

SpriteSheet::SpriteSheet(std::string fileName, Rect _frameRect)
    : framerect(_frameRect)
{
    m_tex = FileLoader::LoadTexture(fileName);
    sz.set( m_tex->getRect().w / framerect.w,
            m_tex->getRect().h / framerect.h );
    frames = sz.x * sz.y;
}

SpriteSheet::SpriteSheet(std::string fileName, Vector2D frameSize)
{
    m_tex = FileLoader::LoadTexture(fileName);
    framerect.w = frameSize.x;
    framerect.h = frameSize.y;
    sz.set( m_tex->getRect().w / framerect.w,
            m_tex->getRect().h / framerect.h );
    frames = sz.x * sz.y;
}

SpriteSheet::SpriteSheet(std::string fileName, int frame_width, int frame_height)
{
    m_tex = FileLoader::LoadTexture(fileName);
    framerect.w = frame_width;
    framerect.h = frame_height;
    sz.set( m_tex->getRect().w / framerect.w,
            m_tex->getRect().h / framerect.h );
    frames = sz.x * sz.y;
}

SpriteSheet::~SpriteSheet()
{
}

void SpriteSheet::Render(int x, int y,Uint16 frame)
{
    if(frame >= frames)
    {
        throw "ERROR: requested frame out of bounds";
    }
    Rect dest(x,y,framerect.w,framerect.h);

    Rect src(framerect.w * (frame%int(sz.x)), framerect.h * (frame /int(sz.x))
             ,framerect.w,framerect.h);
    Drawer::Render(m_tex,&src,&dest);
}

void SpriteSheet::Render(Vector2D vec,Uint16 frame)
{
    if(frame >= frames)
    {
        throw "ERROR: requested frame out of bounds";
    }
    Rect dest(vec.x,vec.y,framerect.w,framerect.h);

    Rect src(framerect.w * (frame%int(sz.x)), framerect.h * (frame /int(sz.x))
             ,framerect.w,framerect.h);
    Drawer::Render(m_tex,&src,&dest);
}

