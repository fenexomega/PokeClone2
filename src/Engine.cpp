#include "Engine.h"
#include <unistd.h>
#include "graphics/Window.h"

extern SDL_Event event;

bool Engine::InitSystems()
{
    bool allGreat;
    allGreat = sysGraphics::Init();
    if(allGreat)
    {
        uLOG("All Systems Initialized. ");
        return true;
    }

    uLOG("Errors occurried. Closing :(");
    return false;
}


void Engine::ShutSystems()
{
    //sysGraphics MUST be the last to shut.
    sysGraphics::Shut();
}

int Engine::Run(iGame *game)
{
    unsigned int framerate = 0;
    float seconds = 0,dt;
    uTime timer;

    if(!InitSystems())
        return -1;

    Window win(800,600,"PokeClone");

    game->Init();

    while(!win.UserWannaQuit())
    {

        timer.Update();

        dt = timer.getDeltaTime();

        seconds += dt;
        framerate++;

        if(seconds >= 1.0f)
        {

            win.appendTitle(" " + std::to_string(framerate) + " FPS");
            framerate = seconds = 0;
        }

        sysInput::update();


        win.clearScreen(0,0,0,255);

        game->Update(dt);

        game->Draw();

        win.SwapBuffers();


    }
    game->Dispose();
    ShutSystems();
    return 0;
}