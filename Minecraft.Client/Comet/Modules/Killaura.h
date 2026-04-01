#pragma once

#include "Module.h"
#include "../Dispatch/Handlers/PlayerTickHandler.h"
#include "../Dispatch/Events/PlayerTickEvent.h"

class Killaura : public Module, public PlayerTickHandler
{
public:
    Killaura();
    void onEvent(std::shared_ptr<PlayerTickEvent> event) override;
};
