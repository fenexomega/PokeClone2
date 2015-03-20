#ifndef ICOMMAND
#define ICOMMAND

class iCommand
{

public:
    iCommand(){}

    virtual ~iCommand(){}
    virtual void Run() = 0;
    virtual void Undo(){}
};

#endif // ICOMMAND

