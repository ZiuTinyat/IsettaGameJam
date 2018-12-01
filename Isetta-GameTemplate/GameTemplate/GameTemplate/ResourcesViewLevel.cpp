// IsettaCore not necessarily needed, holds a number of useful header files
#include <IsettaEngine.h>

#include "ResourcesViewLevel.h"
#include "MyScript.h"
#include "ToResourcesView.h"

using namespace Isetta;



void ResourcesViewLevel::Load() {
	// Level NEEDS a camera
	Entity* cameraEntity = Entity::Instantiate("Camera");
	cameraEntity->AddComponent<CameraComponent>();
	cameraEntity->AddComponent<ToResourcesView>();

	cameraEntity->SetTransform(Math::Vector3{ 0, 5, 10 }, Math::Vector3{ -30, 0, 0 },
		Math::Vector3::one);

	// Light
	Entity* lightEntity{ Entity::Instantiate("Light") };
	lightEntity->AddComponent<LightComponent>();
	lightEntity->SetTransform(Math::Vector3{ 0, 200, 600 }, Math::Vector3::zero,
		Math::Vector3::one);

	// Cube
	Entity* entity;
	entity = Primitive::Create(Primitive::Type::Cube);
	entity->transform->SetWorldPos(Math::Vector3{ 0.0f, 0.0f, 0.0f });
	entity->AddComponent<MyScript>();
}

void ResourcesViewLevel::OnUnload() {
	// Anything you might need to do on the level unloading
	// Entity's will be destructed/destroyed on actual level unload
}
