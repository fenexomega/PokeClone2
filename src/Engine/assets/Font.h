#ifndef FONT_H
#define FONT_H

#include <memory>
#include <SDL2/SDL_ttf.h>

#include "assets/Texture.h"
#include "interfaces/iAsset.h"
#include "graphics/Color.h"
using std::shared_ptr;

class Font : iAsset
{
friend class Drawer;
private:
    TTF_Font* m_font;
    int m_textSize;
    Rect m_rect;
    std::string m_text;
    std::shared_ptr<Texture> m_tex;
    Color m_color;
public:

    Font(std::string _path, std::string _text, int _textSize = 16, Color _color = COLORBLACK);

    //Renderiza o Fonto
    void Render(int x, int y);

    //Seta o texto e retorna a textura desse texto
    shared_ptr<Texture> setFont(std::string _text);

    ~Font();
    Rect rect() const;
};

#endif // FONT_H
