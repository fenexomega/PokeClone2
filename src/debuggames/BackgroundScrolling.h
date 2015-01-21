#ifndef BACKGROUNDSCROLLING_H
#define BACKGROUNDSCROLLING_H

#include "interfaces/iGame.h"
#include "assets/Texture.h"
#include "BackgroundScrolling/Zone.h"

class BackgroundScrolling : public iGame
{
private:
    Zone zone;
public:
    BackgroundScrolling();
    ~BackgroundScrolling();

    // iGame interface
    void Init();
    void Update(float dt);
    void Draw();
    void Dispose();
};

#endif // BACKGROUNDSCROLLING_H
