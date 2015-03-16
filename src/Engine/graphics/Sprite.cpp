#include "Sprite.h"


int Sprite::getSpriteNbr() const
{
    return _spriteNbr;
}

void Sprite::setSpriteNbr(int value)
{
    _spriteNbr = value;
}
Sprite::Sprite(std::string filePath, int w, int h, int _spriteNbr)
    : _spriteNbr(_spriteNbr)
{
    _spst = new SpriteSheet(filePath,w,h);
}

Sprite::Sprite(std::string filePath, Vector2D _size, int _spriteNbr)
    :  _size(_size) ,_spriteNbr(_spriteNbr)
{
    _spst = new SpriteSheet(filePath,_size);

}

Sprite::Sprite(SpriteSheet *spst, int spriteNbr)
    : _spst(spst),_spriteNbr(spriteNbr)
{
    _size = _spst->getSz();
}

void Sprite::Render(int x, int y)
{
    _spst->Render(x,y,_spriteNbr);
}

void Sprite::Render(Vector2D v)
{
    _spst->Render(v,_spriteNbr);
}

Sprite::~Sprite()
{
    delete _spst;
}

