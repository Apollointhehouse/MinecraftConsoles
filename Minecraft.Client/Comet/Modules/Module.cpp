#include "Module.h"
#include "../../Minecraft.h"
#include "../Dispatch/Dispatcher.h"

Minecraft* Module::mc;

Module::Module(wstring name) : name(name)
{
}

void Module::onEnable() {};
void Module::onDisable() {};

void Module::toggle()
{
    mc = Minecraft::GetInstance();
    enabled = !enabled;
    if (enabled)
    {
        Dispatcher::subscribe(this);
        onEnable();
    }
    else
    {
        Dispatcher::unsubscribe(this);
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
