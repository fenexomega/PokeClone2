#ifndef COMPONENTMEDIATOR_H
#define COMPONENTMEDIATOR_H

#include <vector>
#include "interfaces/iComponentMediator.h"

/*Para entender essa classe
 * Exige leitura obrigatória
 * Do livro "Design Patterns"
 * da Gang of Four.
 *
 * Implementando um padrão
 * inspirado no Mediator
 */

class ComponentMediator : public iComponentMediator
{
public:
    std::vector <iComponent *> _components;

    void addComponent(iComponent *cmp);
    ComponentMediator();
    void sendMessage(int msg);
    ~ComponentMediator();
};

#endif // COMPONENTMEDIATOR_H
