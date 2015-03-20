#ifndef ENGINE_H
#define ENGINE_H

#define ENGINE_NAME "Vacilation Engine"


#include <vector>

class iGame;
class iSystem;


class Engine
{
private:
    static iGame *_game;
    static bool _exit;

    static std::vector<iSystem *> systems;
    static  bool InitSystems();
    static void ShutSystems();
    Engine();
public:
    static int Run(iGame *game);
    static void Exit();
};

#endif // ENGINE_H
