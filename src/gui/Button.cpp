#include "Button.h"

#include "systems/sysInput.h"
#include "systems/sysPhysics.h"

Button::Button(int x, int y, Texture *normal, Texture *mouseOver
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

}



void Button::Update(iGameObject &obj)
{
    Vector2D<int> mousePos = sysInput::getMousePos();
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

void Button::Draw()
{
    textures[state]->Render(rect.x,rect.y);
    if(m_text != nullptr)
        m_text->Render( rect.x + (rect.w/2 - m_text->rect().w/2),
                   rect.y + (rect.h/2 - m_text->rect().h/2) );
}
