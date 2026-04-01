#pragma once

#include "Module.h"

class Step : public Module
{
public:
    Step();

    void onEnable() override;
    void onDisable() override;
};
