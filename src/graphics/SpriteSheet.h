#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <iostream>
#include "physics/Rect.h"
#include "assets/Texture.h"
#include "math/Vector2D.h"

class SpriteSheet
{
private:
    typedef unsigned int Uint16;
    Vector2D<int> sz; // in frames
    Uint16 frames;
    Texture *m_tex;
    Rect framerect;

public:
    SpriteSheet(std::string fileName, Rect _frameRect);
    SpriteSheet(std::string fileName, Vector2D<int> frameSize);
    SpriteSheet(std::string fileName, int frame_width,int frame_height);

    ~SpriteSheet();

    void Render(int x, int y, Uint16 frame);
    void Render(Vector2D<int>, Uint16 frame);

    unsigned int getFrames() const;
    Vector2D<int> getSz() const;
};

#endif // SPRITESHEET_H
