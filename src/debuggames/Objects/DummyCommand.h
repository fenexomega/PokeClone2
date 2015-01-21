#ifndef DUMMYCOMMAND_H
#define DUMMYCOMMAND_H

#include <iostream>

#include "interfaces/iCommand.h"

class DummyCommand : public iCommand
{
public:
    DummyCommand();
    ~DummyCommand();

    // iCommand interface
public:
    void Run();
};

#endif // DUMMYCOMMAND_H
