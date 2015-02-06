#ifndef ICOMPONENT
#define ICOMPONENT

#define COMP_GRAPHICS 1
#define COMP_PHYSICS 2
#define COMP_INPUT 3

class iComponent
{
public:

    virtual void receiveMessage(int msg) = 0;

    virtual ~iComponent()
    {
    }
};

#endif // ICOMPONENT

