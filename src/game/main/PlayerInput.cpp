#include "PlayerInput.h"

#include "systems/sysInput.h"

PlayerInput::PlayerInput()
{

}

void PlayerInput::Update(iGameObject *player)
{
    if(sysInput::isKeyPressed(SDL_SCANCODE_W))
        player->acc.y = -1;
    else if(sysInput::isKeyPressed(SDL_SCANCODE_S))
        player->acc.y =  1;
    else if(sysInput::isKeyPressed(SDL_SCANCODE_D))
        player->acc.x =  1;
    else if(sysInput::isKeyPressed(SDL_SCANCODE_A))
        player->acc.x = -1;
//    if( player->acc.x != 0 && player->acc.y != 0 )
//        std::cout << "Daora a vida" << std::endl;
}

PlayerInput::~PlayerInput()
{

}

