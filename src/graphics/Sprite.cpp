#include "Sprite.h"


int Sprite::getSpriteNbr() const
{
    return spriteNbr;
}

void Sprite::setSpriteNbr(int value)
{
    spriteNbr = value;
}
Sprite::Sprite(std::string filePath, int w, int h, int _spriteNbr)
    : spriteNbr(_spriteNbr)
{
    spst = new SpriteSheet(filePath,w,h);
}

Sprite::Sprite(std::string filePath, Vector2D<int> _size, int _spriteNbr)
    :  size(_size) ,spriteNbr(_spriteNbr)
{
    spst = new SpriteSheet(filePath,size);

}

Sprite::Sprite(SpriteSheet *_spst, int _spriteNbr)
    : spst(_spst),spriteNbr(_spriteNbr)
{
    size = spst->getSz();
}

void Sprite::Render(int x, int y)
{
    spst->Render(x,y,spriteNbr);
}

void Sprite::Render(Vector2D<int> v)
{
    spst->Render(v,spriteNbr);
}

Sprite::~Sprite()
{
    delete spst;
}

