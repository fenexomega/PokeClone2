#ifndef TEXT_H
#define TEXT_H

#include <memory>
#include <SDL2/SDL_ttf.h>

#include "assets/Texture.h"
#include "interfaces/iAsset.h"
#include "graphics/Color.h"

class Text : public iAsset
{
private:
    TTF_Font* m_font;
    int m_textSize;
    Rect m_rect;
    std::string m_text;
    Texture *m_tex;
    Color m_color;
public:
    Text(std::string _path, std::string _text, int _textSize = 16, Color _color = COLORBLACK);
    void Render(int x, int y);
    Texture * setText(std::string _text);
    ~Text();
    Rect rect() const;
};

#endif // TEXT_H
