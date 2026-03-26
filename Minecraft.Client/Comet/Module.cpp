#include "Module.h"

Minecraft* Module::mc;

Module::Module(wstring name) : name(name)
{
}

void Module::onEnable() {};
void Module::onDisable() {};

void Module::onPlayerTick() {};

void Module::toggle()
{
    mc = Minecraft::GetInstance();
    enabled = !enabled;
    if (enabled)
    {
        onEnable();
    }
    else
    {
        onDisable();
    }
}

bool Module::isEnabled()
{
    return enabled;
}

wstring Module::getName()
{
    return name;
};
