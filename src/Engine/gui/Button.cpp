#include "Button.h"

#include "systems/sysInput.h"
#include "systems/sysPhysics.h"

#include "graphics/Drawer.h"

Button::Button(int x, int y, std::shared_ptr<Texture> normal, std::shared_ptr<Texture> mouseOver
               , iCommand* command, Font *text)
{
    rect = normal->getRect();
    rect.x = x - rect.w/2;
    rect.y = y - rect.y/2;
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
    delete command;
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
    if(m_text != nullptr)
        m_text->Render( rect.x + (rect.w/2 - m_text->rect().w/2),
                   rect.y + (rect.h/2 - m_text->rect().h/2) );
}
