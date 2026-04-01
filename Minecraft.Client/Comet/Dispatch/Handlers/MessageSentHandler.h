#pragma once
#include "Comet/Dispatch/Events/MessageSentEvent.h"
#include "EventHandler.h"

class MessageSentHandler : public virtual EventHandler
{
  public:
    virtual void onEvent(std::shared_ptr<MessageSentEvent> event) = 0;
};