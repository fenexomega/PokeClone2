#include "SpriteSheet.h"

#include "graphics/Drawer.h"

unsigned int SpriteSheet::getFrames() const
{
    return frames;
}



Vector2D<int> SpriteSheet::getSz() const
{
    return sz;
}


SpriteSheet::SpriteSheet(std::string fileName, Rect _frameRect)
    : framerect(_frameRect)
{
    m_tex = new Texture(fileName);
    sz.set( m_tex->getRect().w / framerect.w,
            m_tex->getRect().h / framerect.h );
    frames = sz.x * sz.y;
}

SpriteSheet::SpriteSheet(std::string fileName, Vector2D<int> frameSize)
{
    m_tex = new Texture(fileName);
    framerect.w = frameSize.x;
    framerect.h = frameSize.y;
    sz.set( m_tex->getRect().w / framerect.w,
            m_tex->getRect().h / framerect.h );
    frames = sz.x * sz.y;
}

SpriteSheet::SpriteSheet(std::string fileName, int frame_width, int frame_height)
{
    m_tex = new Texture(fileName);
    framerect.w = frame_width;
    framerect.h = frame_height;
    sz.set( m_tex->getRect().w / framerect.w,
            m_tex->getRect().h / framerect.h );
    frames = sz.x * sz.y;
}

SpriteSheet::~SpriteSheet()
{
    delete m_tex;
}

void SpriteSheet::Draw(int x, int y,Uint16 frame)
{
    if(frame >= frames)
    {
        throw "ERROR: requested frame out of bounds";
    }
    Rect dest(x,y,framerect.w,framerect.h);

    Rect src(framerect.w * (frame%sz.x), framerect.h * (frame / sz.x)
             ,framerect.w,framerect.h);
    Drawer::Render(m_tex,&src,&dest);
}

