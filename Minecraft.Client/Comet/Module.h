#pragma once

class Module
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

    virtual void onPlayerTick();
};