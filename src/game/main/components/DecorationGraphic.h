#ifndef DECORATIONGRAPHIC_H
#define DECORATIONGRAPHIC_H

#include <memory>
#include "game/components/cGraphic.h"


class Texture;

class DecorationGraphic : public cGraphic
{
private:
    std::shared_ptr<Texture> _tex;
public:
    DecorationGraphic(std::string TexFile,iComponentMediator *mediator);
    ~DecorationGraphic();

    // iComponent interface
    void receiveMessage(int msg);

    // cGraphic interface
    void Update(iGameObject *obj, float dt);
    void Render(iGameObject *obj);
};

#endif // DECORATIONGRAPHIC_H
