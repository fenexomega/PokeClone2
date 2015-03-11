#ifndef SOUNDTEST_H
#define SOUNDTEST_H

#include "interfaces/iGame.h"

class SoundTest : public iGame
{
public:
    SoundTest();
    ~SoundTest();

    // iGame interface
    void Init();
    void Update(float dt);
    void SendMessage(MSG msg);
    void Render();
    void Dispose();
};

#endif // SOUNDTEST_H
