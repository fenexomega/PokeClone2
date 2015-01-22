#include "Rects.h"

#include "graphics/Drawer.h"

void Rects::Init()
{

}

void Rects::Update(float dt)
{

}

void Rects::Draw()
{

    Drawer::drawRect(COLORRED,0,0,100,100);
    Drawer::fillRect(COLORRED,100,0,100,100);


}

void Rects::Dispose()
{

}
