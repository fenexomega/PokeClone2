#include "Button.h"

#include "systems/sysInput.h"
#include "systems/sysPhysics.h"

#include "graphics/Drawer.h"

Button::Button(int x, int y, std::shared_ptr<Texture> normal, std::shared_ptr<Texture> mouseOver
               , iCommand* command, std::shared_ptr<Font> font, std::string text, Color text_color)
    : m_text(text)
{
    rect = normal->getRect();
    rect.x = x - rect.w/2;
    rect.y = y - rect.y/2;
    textures.push_back(normal);
    textures.push_back(mouseOver);
    m_font = font;
    m_text_tex = font->getTexture(text,text_color,rect.w);
    RegisterCommand(command);
}

void Button::RegisterCommand(iCommand *command)
{
    this->command = command;
}

Button::~Button()
{
    delete command;
    textures.clear();
}

void Button::Update()
{
    //TODO fazer um botão melhor que use Observer
    Vector2D mousePos = sysInput::getMousePos();
    bool leftbutton = sysInput::isMouseButtonDown(1);
    Vector2D mouse;
    mouse.x = mousePos.x;
    mouse.y = mousePos.y;
    if(sysPhysics::isColliding(mouse,(this->rect)))
    {
        state = STATE_MOUSE_OVER;
        if(leftbutton)
        {
            if(command != nullptr)
                command->Run();
        }
    }
    else
    {
        state = STATE_NORMAL;
    }

}

void Button::Render()
{
    Drawer::Render(textures[state],rect.x,rect.y);
//    if(m_font != nullptr)
        Drawer::Render(m_text_tex, rect.x + (rect.w/2 - m_text_tex->getRect().w/2),
                   rect.y + (rect.h/2 - m_text_tex->getRect().h/2) );
}
