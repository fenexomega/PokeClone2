#ifndef CGRAPHIC_H
#define CGRAPHIC_H

#include <memory>
#include "interfaces/iComponent.h"
#include "assets/Texture.h"

class cGraphic : public iComponent
{
private:
    std::unique_ptr<Texture> ptr;
    Rect rect;
public:
    cGraphic(std::string file);
    ~cGraphic();

    // iComponent interface
public:
    void Update(iGameObject &obj);
    void Draw();
    void Scale(float w, float h);
};

#endif // CGRAPHIC_H
