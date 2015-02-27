#ifndef ICOMMAND
#define ICOMMAND

class iCommand
{
public:
    virtual void Run() = 0;
    virtual void Undo(){}
};

#endif // ICOMMAND

