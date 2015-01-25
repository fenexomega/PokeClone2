#include "SpriteAnimation.h"



SpriteAnimation::SpriteAnimation(std::string filePath, int amtOfFramesPerAnimation,
                                 int frameWidth, int frameHeight, int _keyFrame)
    : amtOfFrames(amtOfFramesPerAnimation),currentFrame(_keyFrame),keyFrame(_keyFrame)
{
    spst = new SpriteSheet(filePath,frameWidth,frameHeight);
    sizeInTiles = spst->getSz();


}

SpriteAnimation::SpriteAnimation(SpriteSheet *_spst, int amtOfFramesPerAnimation, int _keyFrame)
    : spst(_spst), amtOfFrames(amtOfFramesPerAnimation),currentFrame(_keyFrame),keyFrame(_keyFrame)
{
    sizeInTiles = spst->getSz();

}

SpriteAnimation::~SpriteAnimation()
{
    delete spst;
}

void SpriteAnimation::UpdateAnimation(int i)
{
    //Atualiza o frame atual
    currentFrame += i;
    //Se a animação tiver que voltar ao ponto inicial
    if(currentFrame >= keyFrame + amtOfFrames)
    {
        currentFrame = keyFrame;
    }

}

void SpriteAnimation::Draw(int x, int y)
{
    spst->Draw(x,y,currentFrame);
}

int SpriteAnimation::getKeyFrame() const
{
    return keyFrame;
}

void SpriteAnimation::setKeyFrame(int value)
{
    keyFrame = value;
    currentFrame = keyFrame;
}

