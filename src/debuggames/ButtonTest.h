#ifndef BUTTONTEST_H
#define BUTTONTEST_H

#include "interfaces/iGame.h"

#include "gui/Button.h"
#include "Objects/DummyGameObject.h"


class ButtonTest : public iGame
{
private:
    Button *button;

public:
    DummyGameObject real;

    ButtonTest();
    ~ButtonTest();

    // iGame interface
    void Init();
    void Update(float dt);
    void Render();
    void Dispose();
};

#endif // BUTTONTEST_H
