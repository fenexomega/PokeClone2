#ifndef IGAME_H
#define IGAME_H

#include "gSettings.h"

class MSG
{
public:
    int id;
};

class iGame
{
public:
    virtual void Init() = 0;
    virtual void Update(float dt) = 0;

    virtual void SendMessage(MSG msg) = 0;

    virtual void Render() = 0;

    virtual void Dispose() = 0;

    virtual ~iGame() {};
};

#endif
// IGAME_H
/*
 *
 *
 *
public:
    void Init();
    void Update();
    void Render();
    void Dispose();


void Rects::Init()
{

}

void Rects::Update()
{

}

void Rects::Render()
{

}

void Rects::Dispose()
{

}
*/
