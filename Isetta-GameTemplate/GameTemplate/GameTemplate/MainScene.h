#pragma once
#include <IsettaEngine.h>

using namespace Isetta;
using namespace Math;

DEFINE_LEVEL(MainScene)
void Load() override;
void OnUnload() override;

public:
static Entity* CreateCar(std::string name = "Car", Vector3 pos = Vector3::zero);
static Entity* CreateRoad(std::string name = "Road", Vector3 pos = Vector3::zero);
DEFINE_LEVEL_END