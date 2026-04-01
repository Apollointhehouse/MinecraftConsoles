#pragma once

#include <vector>
#include <string>

#include "Module.h"

class ModuleManager
{
public:
    static ModuleManager &instance();

    void registerModule(Module *module);

    Module *getModuleByName(const std::wstring &name);

    void enableModule(const std::wstring &name);
    void disableModule(const std::wstring &name);

private:
    ModuleManager();
    static std::vector<Module *> modules;
};
