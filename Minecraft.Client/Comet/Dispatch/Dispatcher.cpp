#include "Dispatcher.h"
#include "Handlers/EventHandler.h"
#include "../Comet.h"

void Dispatcher::subscribe(EventHandler* handler) {
    subscribers.insert(handler);
}

void Dispatcher::unsubscribe(EventHandler* handler)
{
    subscribers.erase(handler);
}

namespace
{
    bool registerDefaultHandlers()
    {
        Dispatcher::subscribe(new Comet());
        return true;
    }

    bool registered = registerDefaultHandlers();

}