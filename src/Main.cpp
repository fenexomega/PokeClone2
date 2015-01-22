#include "Engine.h"

#include "game/Game.h"
#include "debuggames/Rects.h"
#include "debuggames/TextureTest.h"
#include "debuggames/MouseTest.h"
#include "debuggames/BackgroundScrolling.h"
#include "debuggames/ButtonTest.h"
#include "debuggames/TextTest.h"

/*@TODO

  FileParser Class
  Entity Class
  Actor Class


  */
int main()
{
    TextTest game;

    Engine engine;
    engine.Run(&game);
    return 0;
}

