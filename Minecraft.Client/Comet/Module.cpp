#include "Module.h"

void Module::onEnable() {};
void Module::onDisable() {};

void Module::onPlayerTick() {};

void Module::toggle()
{
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
