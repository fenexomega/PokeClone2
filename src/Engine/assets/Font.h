#ifndef FONT_H
#define FONT_H

#include <memory>
#include <SDL2/SDL_ttf.h>

#include "assets/Texture.h"
#include "interfaces/iAsset.h"
#include "graphics/Color.h"
using std::shared_ptr;

enum FontAlign : short
{
    CENTER = 0,
    RIGHT,
    LEFT
};

class Font : public iAsset
{
    friend class FileLoader;

private:
    TTF_Font* m_font;
    int m_textSize;

public:
    Font();

    shared_ptr<Texture> getTexture(std::string text,
                                   Color color, Uint32 lineWrap);
    ~Font();
    int textSize() const;
};

#endif // FONT_H
