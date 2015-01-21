#include "CommandTextChanger.h"

CommandTextChanger::CommandTextChanger(Text *text)
{
    this->text = text;
}

CommandTextChanger::~CommandTextChanger()
{

}



void CommandTextChanger::Run()
{
    text->setText("Mudou!");
}
