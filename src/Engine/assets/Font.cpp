#include "Font.h"

#include "io/FileLoader.h"
#include "graphics/Window.h"

#include "graphics/Drawer.h"

#include <memory>


Font::Font(std::string _path, int _textSize) :
    iAsset(AS_FONT), m_textSize(_textSize)
{
    m_font = FileLoader::LoadFont(_path,m_textSize);
}


shared_ptr<Texture> Font::getTexture(std::string text, Color color, Uint32 lineWrap)
{
    SDL_Surface *surface = TTF_RenderUTF8_Blended_Wrapped
            (m_font,text.c_str(),color.toSDLColor(),lineWrap);
    SDL_Texture *tex = SDL_CreateTextureFromSurface
            (Window::getActiveRenderer(),surface);
    auto m_tex = shared_ptr<Texture>(new Texture(tex));
    SDL_FreeSurface(surface);
    return m_tex;
}



Font::~Font()
{
    TTF_CloseFont(m_font);
}

