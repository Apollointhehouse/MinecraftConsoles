#include "Step.h"
#include "../Minecraft.h"
#include "../MultiPlayerLocalPlayer.h"

Step::Step() : Module(L"Step") {}

void Step::onDisable()
{
    auto player = mc->player;

    player->footSize = 1.0F;
}

void Step::onPlayerTick()
{
    auto player = mc->player;

    player->footSize = 5.0F;
}
