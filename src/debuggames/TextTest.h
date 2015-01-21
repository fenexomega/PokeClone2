#ifndef TEXTTEST_H
#define TEXTTEST_H

#include "interfaces/iGame.h"
#include "assets/Text.h"
#include "gui/Button.h"

class TextTest : public iGame
{
private:
    Text*text;
    Button *bt;
public:
    TextTest();
    ~TextTest();

    // iGame interface
    void Init();
    void Update(float dt);
    void Draw();
    void Dispose();
};

#endif // TEXTTEST_H
