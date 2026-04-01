#include "Step.h"
#include "../../Minecraft.h"
#include "../../MultiPlayerLocalPlayer.h"

Step::Step() : Module(L"Step") {}

void Step::onEnable()
{
    auto player = mc->player;

    player->footSize = 5.0F;
}

void Step::onDisable()
{
    auto player = mc->player;

    player->footSize = 0.5F;
}