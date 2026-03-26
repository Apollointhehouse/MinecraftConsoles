#include "Comet.h"

#include "Module.h"
#include "Speed.h"
#include "Step.h"
#include "../Gui.h"
#include "../Minecraft.h"
#include "../../Minecraft.World/StringHelpers.h"

vector<Module*> modules = {
    new Speed(), new Step()
};

bool Comet::handleCommand(std::wstring message)
{
    auto mc = Minecraft::GetInstance();
    for (const auto &module : modules)
    {
        auto cmd = L"/" + module->getName();
        cmd = toLower(cmd);

        message = toLower(message);
        if (message.find(cmd) != 0) { continue; }

        module->toggle();
        wstring status = module->isEnabled() ? L"enabled" : L"disabled";
        mc->gui->addMessage(L"Comet: " + module->getName() + L" " + status, 0, false);
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
