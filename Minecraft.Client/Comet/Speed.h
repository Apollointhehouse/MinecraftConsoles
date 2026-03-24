#pragma once

#include "Module.h"

class Speed : public Module
{
public:
    Speed() : Module() {};
    virtual ~Speed() override = default;
    void onPlayerTick() override;
    void onEnable() override;
};
