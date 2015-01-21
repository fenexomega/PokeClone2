#ifndef COMMANDTEXTCHANGER_H
#define COMMANDTEXTCHANGER_H

#include "interfaces/iCommand.h"

#include "assets/Text.h"

class CommandTextChanger : public iCommand
{
private:
    Text *text;
public:
    CommandTextChanger(Text *text);
    ~CommandTextChanger();
    // iCommand interface
    void Run();
};

#endif // COMMANDTEXTCHANGER_H
