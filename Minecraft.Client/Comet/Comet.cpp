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
    for (const auto &module : modules)
    {
        auto cmd = L"/" + module->name();
        if (message.find(cmd) != 0) { continue; }

        module->toggle();
        wstring status = module->isEnabled() ? L"enabled" : L"disabled";
        mc->gui->addMessage(L"Comet: " + module->name() + L" " + status, 0, false);
        return true;
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
