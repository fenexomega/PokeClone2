#include "Engine.h"

#include "Game.h"
#include "main/MainGame.h"

int main(int argc,char **argv)
{
    Game game;
//    MainGame game(NULL);

    Engine::Run(&game);
    return 0;
}

