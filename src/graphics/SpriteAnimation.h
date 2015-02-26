#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H

#include <iostream>
#include "graphics/SpriteSheet.h"
#include "math/Vector2D.h"

class SpriteAnimation
{
private:
    SpriteSheet *spst;
    int _amtOfFrames;
    int _currentFrame;
    int _keyFrame;

public:

    Vector2D<int> sizeInTiles;
    SpriteAnimation(std::string filePath, int amtOfFramesPerAnimation, int frameWidth,
                    int frameHeight, int _keyFrame = 0 );
    SpriteAnimation(SpriteSheet *_spst,int amtOfFramesPerAnimation,int _keyFrame = 0);
    ~SpriteAnimation();
    void UpdateAnimation(int i = 1);

    void Render(int x, int y);
    void Render(Vector2D<int> pos);

    //getters and Setters
    int getKeyFrame() const;
    void setKeyFrame(int value);
    Vector2D<int> getWidthAndHeight();
    int amtOfFrames() const;
    void setAmtOfFrames(int amtOfFrames);
};

#endif // SPRITEANIMATION_H
