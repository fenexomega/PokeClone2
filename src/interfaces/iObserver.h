#ifndef IOBSERVER
#define IOBSERVER

class iSubject;

class iObserver
{
public:
    virtual void Receive(void* MSG) = 0;
    virtual ~iObserver(){}

};

#endif // IOBSERVER

