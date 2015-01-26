#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>

#include "graphics/SpriteSheet.h"
#include "math/Vector2D.h"

class Sprite
{
private:
    Vector2D<int> size;
    SpriteSheet *spst;
    int spriteNbr;
public:
    Sprite(std::string filePath,int w, int h, int _spriteNbr = 0);
    Sprite(std::string filePath, Vector2D<int> _size, int _spriteNbr = 0);
    Sprite(SpriteSheet *_spst, int _spriteNbr = 0);

    void Render(int x,int y);
    void Render(Vector2D<int> v);

    ~Sprite();
    int getSpriteNbr() const;
    void setSpriteNbr(int value);
};

#endif // SPRITE_H
