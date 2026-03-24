#pragma once

#include <string>

class Comet
{
public:
    static bool handleCommand(std::wstring message);
    static void onPlayerTick();
};
