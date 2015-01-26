#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H

#include <iostream>
#include "graphics/SpriteSheet.h"
#include "math/Vector2D.h"

class SpriteAnimation
{
private:
    SpriteSheet *spst;
    int amtOfFrames,currentFrame,keyFrame;
    Vector2D<int> sizeInTiles;
public:
    SpriteAnimation(std::string filePath, int amtOfFramesPerAnimation, int frameWidth,
                    int frameHeight, int _keyFrame = 0 );
    SpriteAnimation(SpriteSheet *_spst,int amtOfFramesPerAnimation,int _keyFrame = 0);
    ~SpriteAnimation();
    void UpdateAnimation(int i = 1);

    void Render(int x, int y);

    int getKeyFrame() const;
    void setKeyFrame(int value);
};

#endif // SPRITEANIMATION_H
