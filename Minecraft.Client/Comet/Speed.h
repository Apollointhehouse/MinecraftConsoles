#pragma once

#include "Module.h"

class Speed : public Module
{
public:
    Speed() : Module() {};
    virtual ~Speed() override = default;
    wstring name() override { return L"Speed"; };

    void onPlayerTick() override;
};
