#pragma once
#include "Event.h"

struct PlayerTickEvent : public Event
{
    MultiplayerLocalPlayer* player;
};
