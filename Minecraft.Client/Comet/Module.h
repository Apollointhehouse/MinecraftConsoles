#pragma once

class Module
{
    bool enabled = false;

    virtual void onEnable();
    virtual void onDisable();

public:
    virtual ~Module() = default;
    virtual wstring name() = 0;

    void toggle();
    bool isEnabled() const
    {
        return enabled;
    }

    virtual void onPlayerTick();
};