#include "Engine.h"

#include "gSystems.h"
#include "graphics/Window.h"
#include "util/Logger.h"
#include "util/uRandom.h"
#include "io/FileLoader.h"

Engine::Engine()
{
    systems.push_back(new sysGraphics);
    systems.push_back(new sysSound);
    systems.push_back(new sysScripting);
//    systems.push_back(new sysInput);
}

bool Engine::InitSystems()
{
    for(iSystem* i : systems)
        i->Init();
    return true;
}


void Engine::ShutSystems()
{
    //sysGraphics MUST be the last to shut.
    for(iSystem* i : systems)
        i->Dispose();
}

int Engine::Run(iGame *game)
{
    unsigned int framerate = 0;
    float seconds = 0,dt;
    uTime timer;
    uRandom::initRandomSeed();

    Logger::CreateLogFile();

    if(!InitSystems())
        return -1;


    Window win(800,600,"PokeClone");

    game->Init();

    while(!win.UserWannaQuit())
    {

        timer.Update();

        dt = timer.getDeltaTime();
        SDL_Delay(dt);

        seconds += dt;
        framerate++;

        FileLoader::Update();

        if(seconds >= 1.0f)
        {

            win.appendTitle(" " + std::to_string(framerate) + " FPS");
            framerate = seconds = 0;
        }

        sysInput::update();

        for(iSystem *i : systems)
            i->Update();

        win.clearScreen(0,0,0,255);

        game->Update(dt);

        game->Render();

        win.SwapBuffers();

        win.Update();

    }
    game->Dispose();
    win.Destroy();
    ShutSystems();
    Logger::CloseLogFile();

    return 0;
}
