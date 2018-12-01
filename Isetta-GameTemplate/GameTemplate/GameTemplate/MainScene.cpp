// IsettaCore not necessarily needed, holds a number of useful header files
#include <IsettaEngine.h>

#include "MainScene.h"
#include "MyScript.h"
#include "CarControl.h"

using namespace Isetta;
using namespace Math;

void MainScene::Load() {
	// Level NEEDS a camera
	Entity* cameraEntity = Entity::Instantiate("Camera");
	cameraEntity->AddComponent<CameraComponent>();
	cameraEntity->SetTransform(Math::Vector3{ 0, 2, 4 }, Math::Vector3{ -30, 0, 0 },
		Math::Vector3::one);

	// Light
	Entity* lightEntity{ Entity::Instantiate("Light") };
	lightEntity->AddComponent<LightComponent>();
	lightEntity->SetTransform(Math::Vector3{ 0, 200, 600 }, Math::Vector3::zero,
		Math::Vector3::one);
	Entity* lightEntity1{ Entity::Instantiate("Light") };
	lightEntity1->AddComponent<LightComponent>();
	lightEntity1->SetTransform(Math::Vector3{ 0, 200, 600 }, Math::Vector3::zero,
		Math::Vector3::one);

	// Car
	Entity* carEntity = Entity::Instantiate("CarParent");
	Entity* cube0, *cube1, *cube2, *cube3, *cube4, *cube5, *cyl0, *cyl1, *cyl2, *cyl3;
	cube0 = Primitive::Create(Primitive::Type::Cube, "Cube0", false);
	cube0->SetTransform(Vector3{ 0, 0.466f, -0.155f }, Vector3{ 5, 0, 0 }, Vector3{ 0.79f, 0.5f, 0.73f });
	cube0->transform->SetParent(carEntity->transform);
	cube1 = Primitive::Create(Primitive::Type::Cube, "Cube1", false);
	cube1->SetTransform(Vector3{ 0, 0.3f, 0.0f }, Vector3::zero, Vector3{ 0.79f, 0.3f, 2.0f });
	cube1->transform->SetParent(carEntity->transform);
	cube2 = Primitive::Create(Primitive::Type::Cube, "Cube2", true);
	cube2->SetTransform(Vector3{ 0, 0.421f, 0.328f }, Vector3{ 34.6f, 0, 0}, Vector3{ 0.79f, 0.31f, 0.46f });
	cube2->transform->SetParent(carEntity->transform);
	cube3 = Primitive::Create(Primitive::Type::Cube, "Cube3", false);
	cube3->SetTransform(Vector3{ 0, 0.4f, 0.63f }, Vector3{ 9.0f, 0, 0 }, Vector3{ 0.79f, 0.2f, 0.72f });
	cube3->transform->SetParent(carEntity->transform);
	cube4 = Primitive::Create(Primitive::Type::Cube, "Cube4", false);
	cube4->SetTransform(Vector3{ 0, 0.47f, -0.53f }, Vector3{ 125.0f, 0, 0 }, Vector3{ 0.79f, 0.31f, 0.46f });
	cube4->transform->SetParent(carEntity->transform);
	cube5 = Primitive::Create(Primitive::Type::Cube, "Cube5", false);
	cube5->SetTransform(Vector3{ 0, 0.39f, -0.72f }, Vector3{ -9.0f, 0, 0 }, Vector3{ 0.79f, 0.2f, 0.526f });
	cube5->transform->SetParent(carEntity->transform);
	cyl0 = Primitive::Create(Primitive::Type::Cylinder, "cyl0", false);
	cyl0->SetTransform(Vector3{ 0.35f, 0.2f, 0.641f }, Vector3{ 0.0f, 0.0f, 90.0f }, Vector3{ 0.35f, 0.073f, 0.35f });
	cyl0->transform->SetParent(carEntity->transform);
	cyl1 = Primitive::Create(Primitive::Type::Cylinder, "cyl1", false);
	cyl1->SetTransform(Vector3{ 0.35f, 0.2f, -0.518f }, Vector3{ 0.0f, 0.0f, 90.0f }, Vector3{ 0.35f, 0.073f, 0.35f });
	cyl1->transform->SetParent(carEntity->transform);
	cyl2 = Primitive::Create(Primitive::Type::Cylinder, "cyl2", false);
	cyl2->SetTransform(Vector3{ -0.35f, 0.2f, 0.641f }, Vector3{ 0.0f, 0.0f, 90.0f }, Vector3{ 0.35f, 0.073f, 0.35f });
	cyl2->transform->SetParent(carEntity->transform);
	cyl3 = Primitive::Create(Primitive::Type::Cylinder, "cyl3", false);
	cyl3->SetTransform(Vector3{ -0.35f, 0.2f, -0.518f }, Vector3{ 0.0f, 0.0f, 90.0f }, Vector3{ 0.35f, 0.073f, 0.35f });
	cyl3->transform->SetParent(carEntity->transform);

	carEntity->AddComponent<CarControl>();
	/*
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
	*/
}

void MainScene::OnUnload() {
	// Anything you might need to do on the level unloading
	// Entity's will be destructed/destroyed on actual level unload
}
