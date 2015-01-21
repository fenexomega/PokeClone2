#ifndef TEXT_H
#define TEXT_H

#include <memory>
#include <SDL2/SDL_ttf.h>

#include "assets/Texture.h"
#include "interfaces/iAsset.h"


class Text : iAsset
{
private:
    std::shared_ptr<TTF_Font> font;
    int textSize;
    Rect rect;
public:
    Text(std::string _path,int _textSize,Rect _rect);
    ~Text();
};

#endif // TEXT_H
