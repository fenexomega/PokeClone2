#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>

#include "graphics/SpriteSheet.h"
#include "math/Vector2D.h"

class Sprite
{
private:
    Vector2D _size;
    SpriteSheet *_spst;
    int _spriteNbr;
public:
    Sprite(std::string filePath,int w, int h, int _spriteNbr = 0);
    Sprite(std::string filePath, Vector2D _size, int _spriteNbr = 0);
    Sprite(SpriteSheet *spst, int _spriteNbr = 0);

    void Render(int x,int y);
    void Render(Vector2D v);

    ~Sprite();
    int getSpriteNbr() const;
    void setSpriteNbr(int value);
};

#endif // SPRITE_H
