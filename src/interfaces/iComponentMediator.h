#ifndef ICOMPONENTMEDIATOR
#define ICOMPONENTMEDIATOR

class iComponent;

class iComponentMediator
{
public:
    virtual void sendMessage(int msg) = 0;
    virtual void addComponent(iComponent *cmp) = 0;
    virtual ~iComponentMediator() {}

};

#endif // ICOMPONENTMEDIATOR

