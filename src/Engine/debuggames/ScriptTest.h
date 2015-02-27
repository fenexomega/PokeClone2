#ifndef SCRIPTTEST_H
#define SCRIPTTEST_H

#include "interfaces/iGame.h"
#include "assets/Script.h"

class ScriptTest : public iGame
{
private:
    Script* script;
public:
    ScriptTest();
    ~ScriptTest();

    // iGame interface
    void Init();
    void Update(float dt);
    void SendMessage(MSG msg);
    void Render();
    void Dispose();
};

#endif // SCRIPTTEST_H
