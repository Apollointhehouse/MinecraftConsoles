#pragma once

#include "../Dispatch/Handlers/EventHandler.h"
#include "../Dispatch/Dispatcher.h"

class Module : public virtual EventHandler
{
    wstring name;
    bool enabled = false;

    virtual void onEnable();
    virtual void onDisable();

  protected:
    static Minecraft *mc;

    Module(wstring name);

  public:
    virtual ~Module() = default;

    wstring getName();
    void toggle();
    bool isEnabled();
};
