#include "Engine.h"

#include "gSystems.h"
#include "graphics/Window.h"
#include "util/Logger.h"
#include "util/uRandom.h"
#include "io/FileLoader.h"

std::vector<iSystem *> Engine::systems;



bool Engine::InitSystems()
{
    systems.push_back(new sysGraphics);
    systems.push_back(new sysSound);
    systems.push_back(new sysScripting);

    for(iSystem* i : systems)
        i->Init();
    return true;
}


void Engine::ShutSystems()
{
    for(iSystem* i : systems)
        i->Dispose();
}

int Engine::Run(iGame *game)
{
    InitSystems();

    unsigned int framerate = 0;
    float seconds = 0;
    float dt;
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

        dt = timer.getDeltaTime();

        seconds += dt;
        framerate++;
        SDL_Delay(dt);

    }
    Logger::CloseLogFile();
    game->Dispose();
    win.Destroy();
    FileLoader::Clear();
    ShutSystems();

    return 0;
}
