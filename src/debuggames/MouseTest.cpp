#include "MouseTest.h"

#include "graphics/Drawer.h"

void MouseTest::Init()
{
    mouse = new RenderMe("Contents/Debug/mouse.png");
}

void MouseTest::Update(float dt)
{

    for (int var = 0; var < 3; ++var)
        squares[var] = false;

    if(sysInput::isMouseButtonPressed(1))
        squares[0] = true;
    if(sysInput::isMouseButtonPressed(2))
        squares[1] = true;
    if(sysInput::isMouseButtonPressed(3))
        squares[2] = true;

}

void MouseTest::Render()
{
    Drawer::clearScreen(255,255,255,255);
    if(squares[0])
        Drawer::fillRect(COLORGREEN,0,0,155,200);
    if(squares[2])
        Drawer::fillRect(COLORBLUE,153,0,150,200);
    Drawer::fillRect(COLORWHITE,145,50,20,110);
    if(squares[1])
        Drawer::fillRect(COLORRED,145,50,20,110);

    mouse->Render();

}

void MouseTest::Dispose()
{
    delete mouse;
}
