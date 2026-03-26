#pragma once

#include "Module.h"

class Step : public Module
{
public:
    Step();

    void onPlayerTick() override;
    void onDisable() override;
};
