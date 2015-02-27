#include "SpriteAnimation.h"




int SpriteAnimation::amtOfFrames() const
{
    return _amtOfFrames;
}

void SpriteAnimation::setAmtOfFrames(int amtOfFrames)
{
    _amtOfFrames = amtOfFrames;
}
SpriteAnimation::SpriteAnimation(std::string filePath, int amtOfFramesPerAnimation,
                                 int frameWidth, int frameHeight, int _keyFrame)
    : _amtOfFrames(amtOfFramesPerAnimation),_currentFrame(_keyFrame),_keyFrame(_keyFrame)
{
    spst = new SpriteSheet(filePath,frameWidth,frameHeight);
    sizeInTiles = spst->getSz();


}

SpriteAnimation::SpriteAnimation(SpriteSheet *_spst, int amtOfFramesPerAnimation, int _keyFrame)
    : spst(_spst), _amtOfFrames(amtOfFramesPerAnimation),_currentFrame(_keyFrame),_keyFrame(_keyFrame)
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
    _currentFrame += i;
    //Se a animação tiver que voltar ao ponto inicial
    if(_currentFrame >= _keyFrame + _amtOfFrames)
    {
        _currentFrame = _keyFrame;
    }

}

void SpriteAnimation::Render(int x, int y)
{
    spst->Render(x,y,_currentFrame);
}

void SpriteAnimation::Render(Vector2D<int> pos)
{
    spst->Render(pos,_currentFrame);

}


int SpriteAnimation::getKeyFrame() const
{
    return _keyFrame;
}

void SpriteAnimation::setKeyFrame(int value)
{
    _keyFrame = value;
    _currentFrame = _keyFrame;
}

Vector2D<int> SpriteAnimation::getWidthAndHeight()
{
    Vector2D<int> aux;
    Rect aux_rect = spst->getFramerect();
    aux.set(aux_rect.w,aux_rect.h);
    return aux;
}

