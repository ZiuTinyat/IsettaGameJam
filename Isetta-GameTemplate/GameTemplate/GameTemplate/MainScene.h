#pragma once
#include <IsettaEngine.h>

using namespace Isetta;

DEFINE_LEVEL(MainScene)
void Load() override;
void OnUnload() override;

Entity* CreateCar(std::string name);
DEFINE_LEVEL_END