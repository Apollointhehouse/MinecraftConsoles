#include "Comet.h"

#include "Modules/Module.h"
#include "Modules/Speed.h"
#include "Modules/Step.h"
#include "Modules/ModuleManager.h"
#include "Dispatch/Handlers/EventHandler.h"
#include "../Gui.h"
#include "../Minecraft.h"
#include "../../Minecraft.World/StringHelpers.h"

Comet::Comet()
{
    auto manager = ModuleManager::instance();
}

void Comet::onEvent(shared_ptr<MessageSentEvent> event)
{
    auto mc = Minecraft::GetInstance();
    auto message = event->message;
    message = toLower(message);

    if (message.size() == 0) return;

    if (message[0] != L'/') return;

    // extract command
    std::wstring cmd = trimString(message.substr(1));

    Module *module = ModuleManager::instance().getModuleByName(cmd);
    if (module != nullptr)
    {
        module->toggle();
        wstring status = module->isEnabled() ? L"enabled" : L"disabled";
        mc->gui->addMessage(L"Comet: " + module->getName() + L" " + status, 0, false);
        event->cancel();
    }
}

void Comet::onEvent(shared_ptr<PlayerTickEvent> event)
{

    // for (const auto& module : modules)
    // {
    //     if (module->isEnabled())
    //     {
    //         module->onPlayerTick();
    //     }
    // }
}
