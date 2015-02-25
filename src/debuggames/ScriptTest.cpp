#include "ScriptTest.h"

#include "systems/sysScripting.h"

ScriptTest::ScriptTest()
{

}

ScriptTest::~ScriptTest()
{

}



void ScriptTest::Init()
{
    script = new Script("Contents/test.lua");
}

void ScriptTest::Update(float dt)
{
    script->getState()["test"]();
}

void ScriptTest::SendMessage(MSG msg)
{
}

void ScriptTest::Render()
{
}

void ScriptTest::Dispose()
{
}
