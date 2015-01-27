#include "PlayerInput.h"

#include "systems/sysInput.h"

PlayerInput::PlayerInput()
{

}

void PlayerInput::Update(iGameObject *obj)
{
    obj->acc = Vector2D<int>(0,0);
    if(sysInput::isKeyPressed(SDL_SCANCODE_W))
        obj->acc.y = -1;
    else if(sysInput::isKeyPressed(SDL_SCANCODE_S))
        obj->acc.y =  1;
    else if(sysInput::isKeyPressed(SDL_SCANCODE_D))
        obj->acc.x =  1;
    else if(sysInput::isKeyPressed(SDL_SCANCODE_A))
        obj->acc.x = -1;
//    if( player->acc.x != 0 && player->acc.y != 0 )
//        std::cout << "Daora a vida" << std::endl;
}

PlayerInput::~PlayerInput()
{

}



void PlayerInput::receiveMessage(int msg)
{
}
