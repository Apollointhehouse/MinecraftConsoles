#include <memory>
#include <string>
#include <vector>

#include "../../../Minecraft.World/StringHelpers.h"
#include "Module.h"
#include "ModuleManager.h"

#include "Killaura.h"
#include "Speed.h"
#include "Step.h"


ModuleManager& ModuleManager::instance()
{
    static ModuleManager inst;
    return inst;
}

void ModuleManager::registerModule(Module *module)
{
    modules.push_back(module);
}

Module* ModuleManager::getModuleByName(const std::wstring &name)
{
    for (const auto m : modules)
    {
        if (toLower(m->getName()) == toLower(name))
        {
            return m;
        }
    }
    return nullptr;
}

void ModuleManager::enableModule(const std::wstring &name)
{
    Module *module = getModuleByName(name);
    if (module && !module->isEnabled())
    {
        module->toggle();
    }
}

void ModuleManager::disableModule(const std::wstring &name)
{
    Module *module = getModuleByName(name);
    if (module && module->isEnabled())
    {
        module->toggle();
    }
}

std::vector<Module *> ModuleManager::modules = {};
ModuleManager::ModuleManager() = default;

namespace
{
    bool registerModuleDefault()
    {
        auto &manager = ModuleManager::instance();
        manager.registerModule(new Speed());
        manager.registerModule(new Step());
        manager.registerModule(new Killaura());

        return true;
    }

    bool registered = registerModuleDefault();
}
