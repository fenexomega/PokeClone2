#include "Button.h"

#include "systems/sysInput.h"
#include "systems/sysPhysics.h"

#include "graphics/Drawer.h"

Button::Button(int x, int y, std::shared_ptr<Texture> normal, std::shared_ptr<Texture> mouseOver
               , iCommand* command, Text *text)
{
    rect = normal->getRect();
    rect.x = x;
    rect.y = y;
    textures.push_back(normal);
    textures.push_back(mouseOver);
    m_text = text;
    RegisterCommand(command);
}

void Button::RegisterCommand(iCommand *command)
{
    this->command = command;
}

Button::~Button()
{
    delete m_text;

}

void Button::Update()
{
    //TODO fazer um botão melhor que use Observer
    Vector2D mousePos = sysInput::getMousePos();
    bool leftbutton = sysInput::isMouseButtonDown(1);
    Rect mouse (0,0,1,1);
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
    if(m_text != nullptr)
        m_text->Render( rect.x + (rect.w/2 - m_text->rect().w/2),
                   rect.y + (rect.h/2 - m_text->rect().h/2) );
}
