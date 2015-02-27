#ifndef ISUBJECT
#define ISUBJECT

#include <vector>
#include "interfaces/iObserver.h"

class iSubject
{
public:
    inline  void AddObserver(iObserver *observer)
    {
        _obsevers.push_back(observer);
    }

    inline void Notify(void* MSG)
    {
        for(iObserver* i : _obsevers)
        {
            i->Receive(MSG);
        }
    }

    inline void RemObserver(iObserver *observer)
    {
        for(auto i = _obsevers.begin(); i != _obsevers.end(); ++i)
            if(*i == observer)
            {
                _obsevers.erase(i);
                break;
            }
    }

    virtual ~iSubject(){}
private:
    std::vector<iObserver *> _obsevers;
};

#endif // ISUBJECT

