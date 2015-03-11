#include "Engine.h"

#include "Game.h"
#include "main/MainGame.h"
//#include "debuggames/RectsTest.h"
//#include "debuggames/TextureTest.h"
//#include "debuggames/MouseTest.h"
//#include "debuggames/BackgroundScrolling.h"
//#include "debuggames/ButtonTest.h"
//#include "debuggames/TextTest.h"
//#include "debuggames/TileMapTest.h"
//#include "debuggames/SpriteSheetTest.h"
//#include "debuggames/PhysicsTest.h"
//#include "debuggames/ScriptTest.h"

int main(int argc,char **argv)
{
    Game game;
//    MainGame game(NULL);

    Engine::Run(&game);
    return 0;
}
