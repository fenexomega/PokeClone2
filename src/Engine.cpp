#include "Engine.h"

#include "graphics/Window.h"
#include "util/Logger.h"
#include "systems/sysGraphics.h"
#include "systems/sysSound.h"
#include "systems/sysInput.h"


Engine::Engine()
{
    systems.push_back(new sysGraphics);
    systems.push_back(new sysSound);
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
    win.Destroy();
    ShutSystems();
    Logger::CloseLogFile();

    return 0;
}
