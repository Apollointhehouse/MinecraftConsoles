#pragma once

#include "Module.h"
#include "Comet/Dispatch/Events/PlayerTickEvent.h"
#include "Comet/Dispatch/Handlers/PlayerTickHandler.h"

class Speed : public Module, public PlayerTickHandler
{
public:
    Speed();

    void onEvent(shared_ptr<PlayerTickEvent> event) override;
};
