#include "RectsTest.h"

#include "graphics/Drawer.h"

void RectsTests::Init()
{

}

void RectsTests::Update(float dt)
{

}

void RectsTests::Render()
{

    Drawer::drawRect(COLORRED,0,0,100,100);
    Drawer::fillRect(COLORRED,100,0,100,100);


}

void RectsTests::Dispose()
{

}
