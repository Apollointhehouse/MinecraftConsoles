#include "Killaura.h"

#include "../../MultiPlayerLevel.h"
#include "../../MultiPlayerLocalPlayer.h"
#include "../../../Minecraft.World/AABB.h"

#include <memory>

Killaura::Killaura() : Module(L"Killaura")
{
}

void Killaura::onEvent(std::shared_ptr<PlayerTickEvent> event)
{
    MultiplayerLocalPlayer* player = event->player;
    MultiPlayerLevel* world = mc->level;

    AABB* bb = player->bb->grow(5.0, 5.0, 5.0);
    std::vector<std::shared_ptr<Entity>>* entities = world->getEntities(std::make_shared<MultiplayerLocalPlayer>(*player), bb);
    
    
    for (auto entity : *entities)
    {
        if (!entity)
        {
            continue;
        }
        player->attack(entity);
    }
}
