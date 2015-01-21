#include "Text.h"

#include "io/FileLoader.h"
#include "graphics/Window.h"

Text::Text(std::string _path, std::string _text, int _textSize, Rect _rect, Color _color) :
    iAsset(AS_FONT), m_text(_text), m_textSize(_textSize), m_rect(_rect),m_color(_color)
{
    m_font = FileLoader::LoadFont(_path,m_textSize);
    setText(_text);
}

void Text::Render()
{
    m_tex->Render(m_rect);
}

Texture *Text::setText(std::string _text)
{
    m_text = _text;
    SDL_Surface *surface = TTF_RenderText_Blended(m_font,_text.c_str(),m_color.toSDLColor());
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Window::getActiveRenderer(),surface);
    m_tex = new Texture(tex);
    SDL_FreeSurface(surface);
    return m_tex;
}




Text::~Text()
{
    TTF_CloseFont(m_font);
}

