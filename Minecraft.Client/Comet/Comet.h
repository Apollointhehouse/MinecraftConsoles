#pragma once

#include "Dispatch/Events/MessageSentEvent.h"
#include "Dispatch/Handlers/PlayerTickHandler.h"
#include "Dispatch/Events/PlayerTickEvent.h"
#include "Dispatch/Handlers/MessageSentHandler.h"

#include <memory>

using std::shared_ptr;

class Comet : public virtual PlayerTickHandler, public virtual MessageSentHandler
{
public:
    Comet();
    virtual ~Comet() = default;
    void onEvent(std::shared_ptr<MessageSentEvent> event) override;
    void onEvent(std::shared_ptr<PlayerTickEvent> event) override;
};
