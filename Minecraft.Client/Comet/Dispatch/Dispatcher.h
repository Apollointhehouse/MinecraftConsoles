#pragma once

#include "Handlers/EventHandler.h"

#include <memory>

class Dispatcher
{
    inline static std::unordered_set<EventHandler *> subscribers;

  public:
    template <typename Evt, typename Handler>
    static void onEvent(const Evt &event)
    {
        auto evPtr = std::make_shared<Evt>(event);
        for (auto handler : subscribers)
        {
            auto type_handler = dynamic_cast<Handler*>(handler);
            if (type_handler == nullptr)
            {
                continue;
            }

            type_handler->onEvent(evPtr);
        }
    }

    static void subscribe(EventHandler* handler);
    static void unsubscribe(EventHandler* handler);
};
