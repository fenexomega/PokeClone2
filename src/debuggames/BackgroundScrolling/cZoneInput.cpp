#include "cZoneInput.h"
#include "systems/sysInput.h"

cZoneInput::cZoneInput()
{

}

cZoneInput::~cZoneInput()
{

}



void cZoneInput::Update(iGameObject &obj)
{
    if(sysInput::isKeyPressed(SDL_SCANCODE_A))
        obj.rect.x += 5;
    if(sysInput::isKeyPressed(SDL_SCANCODE_D))
        obj.rect.x -= 5;
    if(sysInput::isKeyPressed(SDL_SCANCODE_S))
        obj.rect.y -= 5;
    if(sysInput::isKeyPressed(SDL_SCANCODE_W))
        obj.rect.y += 5;
}



void cZoneInput::Render()
{
}
