#include "Comet.h"

#include "Module.h"
#include "Speed.h"
#include "../Gui.h"
#include "../Minecraft.h"

vector<Module*> modules = {
    new Speed()
};

bool Comet::handleCommand(std::wstring message)
{
    auto mc = Minecraft::GetInstance();
    mc->gui->addMessage(L"Comet: Toggling Modules", 0, false);
    for (const auto &module : modules)
    {
        module->toggle();
    }

    return false;
}

void Comet::onPlayerTick()
{
    for (const auto& module : modules)
    {
        if (module->isEnabled())
        {
            module->onPlayerTick();
        }
    }
}
