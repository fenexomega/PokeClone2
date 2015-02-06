#ifndef MESSAGESENDER_H
#define MESSAGESENDER_H

#include "interfaces/iComponentMediator.h"

class MessageSender
{
private:
    iComponentMediator *mediator = nullptr;
public:
    MessageSender(iComponentMediator *mediator);
    void sendMessage(int msg);
    ~MessageSender();
};

#endif // MESSAGESENDER_H
