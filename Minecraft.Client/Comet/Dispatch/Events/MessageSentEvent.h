#pragma once
#include "Cancelable.h"
#include "Event.h"
#include <string>

struct MessageSentEvent : public Event, public Cancelable
{
    std::wstring message;
};
