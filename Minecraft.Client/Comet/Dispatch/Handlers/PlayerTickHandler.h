#pragma once
#include "EventHandler.h"
#include "Comet/Dispatch/Events/PlayerTickEvent.h"

class PlayerTickHandler : public virtual EventHandler
{
public:
    virtual void onEvent(std::shared_ptr<PlayerTickEvent> event) = 0;
};
