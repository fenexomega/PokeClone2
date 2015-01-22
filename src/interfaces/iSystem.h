#ifndef ISYSTEM_H
#define ISYSTEM_H

class iSystem
{
//    Não colocar construtores
public:
    virtual bool Init() = 0;
    virtual void Update() = 0;
    virtual void Dispose() = 0;
};

#endif // ISYSTEM_H
