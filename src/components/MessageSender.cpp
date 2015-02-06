#include "MessageSender.h"

#include "util/Logger.h"

MessageSender::MessageSender(iComponentMediator *mediator)
    : mediator(mediator)
{

}

void MessageSender::sendMessage(int msg)
{
    mediator->sendMessage(msg);
}

MessageSender::~MessageSender()
{

}

