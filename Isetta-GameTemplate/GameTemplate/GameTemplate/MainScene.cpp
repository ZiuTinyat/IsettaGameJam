// IsettaCore not necessarily needed, holds a number of useful header files
#include <IsettaEngine.h>

#include "MainScene.h"
#include "MyScript.h"

using namespace Isetta;

void MainScene::Load() {
	// Level NEEDS a camera
	Entity* cameraEntity = Entity::Instantiate("Camera");
	cameraEntity->AddComponent<CameraComponent>();
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

	// Child
	Entity* entity2;
	entity2 = Primitive::Create(Primitive::Type::Cube);
	entity2->transform->SetWorldPos(Math::Vector3{ 0.0f, 2.0f, 0.0f });
	entity2->transform->SetLocalScale(Math::Vector3{ 0.25f, 2.0f, 0.25f });
	entity2->transform->SetParent(entity->transform);
}

void MainScene::OnUnload() {
	// Anything you might need to do on the level unloading
	// Entity's will be destructed/destroyed on actual level unload
}
