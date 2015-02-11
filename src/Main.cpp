#include "Engine.h"

#include "game/Game.h"
#include "game/main/MainGame.h"
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

int main()
{
    MainGame game(NULL);

    Engine engine;
    engine.Run(&game);
    return 0;
}

