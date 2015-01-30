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

void SpriteAnimation::Render(int x, int y)
{
    spst->Render(x,y,currentFrame);
}

void SpriteAnimation::Render(Vector2D<int> pos)
{
    spst->Render(pos,currentFrame);

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

Vector2D<int> SpriteAnimation::getWidthAndHeight()
{
    Vector2D<int> aux;
    Rect aux_rect = spst->getFramerect();
    aux.set(aux_rect.w,aux_rect.h);
    return aux;
}

