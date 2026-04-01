#include "Speed.h"
#include "../../../Minecraft.World/Vec3.h"
#include "../../MultiPlayerLocalPlayer.h"
#include "../../Input.h"

Speed::Speed() : Module(L"Speed") {}

void Speed::onEvent(shared_ptr<PlayerTickEvent> event)
{
    auto player = event->player;
    Input *input = player->input;

    auto isMovingKey = input->ya != 0.0F || input->xa != 0.0F;
    auto isMoving = player->xd != 0.0 || player->zd != 0.0;
    
    if (!isMovingKey || !isMoving)
    {
        return;
    }
    
    auto dir = Vec3::newTemp(
        -sin(player->yRot * PI / 180.0),
        -sin(player->xRot * PI / 180.0),
        cos(player->yRot * PI / 180.0));

    auto maxSpeed = 6.0;
    auto addSpeedX = dir->x * maxSpeed / 10;
    auto addSpeedZ = dir->z * maxSpeed / 10;
    
    player->xd = input->ya * addSpeedX + input->xa * addSpeedZ;
    player->zd = -input->xa * addSpeedX + input->ya * addSpeedZ;
}
