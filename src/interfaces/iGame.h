#ifndef IGAME_H
#define IGAME_H

class iGame
{
public:
    virtual void Init() = 0;
    virtual void Update(float dt) = 0;

    //TODO isso daqui deveria receber uma textura para desenhar
    virtual void Draw() = 0;

    virtual void Dispose() = 0;
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
    void Draw();
    void Dispose();


void Rects::Init()
{

}

void Rects::Update()
{

}

void Rects::Draw()
{

}

void Rects::Dispose()
{

}
*/
