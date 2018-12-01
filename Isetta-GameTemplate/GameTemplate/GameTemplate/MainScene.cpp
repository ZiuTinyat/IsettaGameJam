// IsettaCore not necessarily needed, holds a number of useful header files
#include <IsettaEngine.h>

#include "MainScene.h"
#include "MyScript.h"
#include "CarControl.h"
#include "GameManager.h"
//#include "Components/Editor/EditorComponent.h"

using namespace Isetta;
using namespace Math;

void MainScene::Load() {
	// Level NEEDS a camera
	Entity* cameraEntity = Entity::Instantiate("Camera");
	cameraEntity->AddComponent<CameraComponent>();
	cameraEntity->SetTransform(Vector3{ 0, 2, -3 }, Vector3{ -30, 180, 0 },
		Math::Vector3::one);
	//cameraEntity->AddComponent<EditorComponent>();

	// Light
	Entity* lightEntity{ Entity::Instantiate("Light") };
	lightEntity->AddComponent<LightComponent>();
	lightEntity->SetTransform(Vector3{ 500, 400, -300 }, Vector3{ -180, 0, 0 }, Vector3::one);
	Entity* lightEntity1{ Entity::Instantiate("Light1") };
	lightEntity1->AddComponent<LightComponent>();
	lightEntity1->SetTransform(Vector3{ -500, 400, -300 }, Vector3{ -180, 0, 0 }, Vector3::one);

	// Road
	Entity* roadEntity = Entity::Instantiate("Road");
	roadEntity->transform->SetWorldPos(Vector3::back * 20);
	roadEntity->AddComponent<GameManager>();

	Entity* carEntity = CreateCar("PlayerCar");
}

Entity* MainScene::CreateCar(std::string name, Vector3 pos) {
	Entity* carEntity = Entity::Instantiate(name);
	Entity* cube0, *cube1, *cube2, *cube3, *cube4, *cube5, *cyl0, *cyl1, *cyl2, *cyl3;
	cube0 = Primitive::Create(Primitive::Type::Cube, "Cube0", false);
	cube0->SetTransform(Vector3{ 0, 0.466f, -0.155f }, Vector3{ 5, 0, 0 }, Vector3{ 0.79f, 0.5f, 0.73f });
	cube0->transform->SetParent(carEntity->transform);
	cube1 = Primitive::Create(Primitive::Type::Cube, "Cube1", false);
	cube1->SetTransform(Vector3{ 0, 0.3f, 0.0f }, Vector3::zero, Vector3{ 0.79f, 0.3f, 2.0f });
	cube1->transform->SetParent(carEntity->transform);
	cube2 = Primitive::Create(Primitive::Type::Cube, "Cube2", false);
	cube2->SetTransform(Vector3{ 0, 0.421f, 0.328f }, Vector3{ 34.6f, 0, 0 }, Vector3{ 0.79f, 0.31f, 0.46f });
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
	//cyl0->SetTransform(Vector3{ 0.35f, 0.2f, 0.641f }, Vector3{ 0.0f, 0.0f, 90.0f }, Vector3{ 0.35f, 0.073f, 0.35f });
	cyl0->SetTransform(Vector3{ 0.35f, 0.2f, 0.641f }, Vector3{ 0.0f, 0.0f, 90.0f }, Vector3{ 0.073f,  0.35f, 0.35f });
	cyl0->transform->SetParent(carEntity->transform);
	cyl1 = Primitive::Create(Primitive::Type::Cylinder, "cyl1", false);
	//cyl1->SetTransform(Vector3{ 0.35f, 0.2f, -0.518f }, Vector3{ 0.0f, 0.0f, 90.0f }, Vector3{ 0.35f, 0.073f, 0.35f });
	cyl1->SetTransform(Vector3{ 0.35f, 0.2f, -0.518f }, Vector3{ 0.0f, 0.0f, 90.0f }, Vector3{ 0.073f,  0.35f, 0.35f });
	cyl1->transform->SetParent(carEntity->transform);
	cyl2 = Primitive::Create(Primitive::Type::Cylinder, "cyl2", false);
	//cyl2->SetTransform(Vector3{ -0.35f, 0.2f, 0.641f }, Vector3{ 0.0f, 0.0f, 90.0f }, Vector3{ 0.35f, 0.073f, 0.35f });
	cyl2->SetTransform(Vector3{ -0.35f, 0.2f, 0.641f }, Vector3{ 0.0f, 0.0f, 90.0f }, Vector3{ 0.073f,  0.35f, 0.35f });
	cyl2->transform->SetParent(carEntity->transform);
	cyl3 = Primitive::Create(Primitive::Type::Cylinder, "cyl3", false);
	//cyl3->SetTransform(Vector3{ -0.35f, 0.2f, -0.518f }, Vector3{ 0.0f, 0.0f, 90.0f }, Vector3{ 0.35f, 0.073f, 0.35f });
	cyl3->SetTransform(Vector3{ -0.35f, 0.2f, -0.518f }, Vector3{ 0.0f, 0.0f, 90.0f }, Vector3{ 0.073f,  0.35f, 0.35f });
	cyl3->transform->SetParent(carEntity->transform);

	Entity* boost0, *boost1;
	boost0 = Primitive::Create(Primitive::Type::Cube, "b0", false);
	boost0->SetTransform(Vector3{ 0.24f, 0.295f, 0.984f }, Vector3::zero, Vector3{ 0.1f,  0.1f, 0.001f });
	boost0->transform->SetParent(carEntity->transform);
	boost1 = Primitive::Create(Primitive::Type::Cube, "b1", false);
	boost1->SetTransform(Vector3{ -0.24f, 0.295f, 0.984f }, Vector3::zero, Vector3{ 0.1f,  0.1f, 0.001f });
	boost1->transform->SetParent(carEntity->transform);

	carEntity->AddComponent<CarControl>();
	carEntity->GetComponent<CarControl>()->boost0 = boost0;
	carEntity->GetComponent<CarControl>()->boost1 = boost1;
	carEntity->transform->SetWorldPos(pos);

	return carEntity;
}

Entity* MainScene::CreateRoad(std::string name, Vector3 pos) {
	Entity* roadEntity = Entity::Instantiate(name);
	Entity* cube0, *cube1, *cube2, *cube3, *cube4, *cube5, *cube6, *cube7, *cube8, *cube9;
	cube0 = Primitive::Create(Primitive::Type::Cube, "Cube0", false);
	cube0->SetTransform(Vector3{ 3, 0, 10 }, Vector3::zero, Vector3{ 0.2f, 0.2f, 20 });
	cube0->transform->SetParent(roadEntity->transform);
	cube1 = Primitive::Create(Primitive::Type::Cube, "Cube1", false);
	cube1->SetTransform(Vector3{ -3, 0, 10 }, Vector3::zero, Vector3{ 0.2f, 0.2f, 20 });
	cube1->transform->SetParent(roadEntity->transform);
	cube2 = Primitive::Create(Primitive::Type::Cube, "Cube2", false);
	cube2->SetTransform(Vector3{ 1, 0, 2.5f }, Vector3::zero, Vector3{ 0.2f, 0.01f, 3 });
	cube2->transform->SetParent(roadEntity->transform);
	cube3 = Primitive::Create(Primitive::Type::Cube, "Cube3", false);
	cube3->SetTransform(Vector3{ -1, 0, 2.5f }, Vector3::zero, Vector3{ 0.2f, 0.01f, 3 });
	cube3->transform->SetParent(roadEntity->transform);
	cube4 = Primitive::Create(Primitive::Type::Cube, "Cube4", false);
	cube4->SetTransform(Vector3{ 1, 0, 7.5f }, Vector3::zero, Vector3{ 0.2f, 0.01f, 3 });
	cube4->transform->SetParent(roadEntity->transform);
	cube5 = Primitive::Create(Primitive::Type::Cube, "Cube5", false);
	cube5->SetTransform(Vector3{ -1, 0, 7.5f }, Vector3::zero, Vector3{ 0.2f, 0.01f, 3 });
	cube5->transform->SetParent(roadEntity->transform);
	cube6 = Primitive::Create(Primitive::Type::Cube, "Cube6", false);
	cube6->SetTransform(Vector3{ 1, 0, 12.5f }, Vector3::zero, Vector3{ 0.2f, 0.01f, 3 });
	cube6->transform->SetParent(roadEntity->transform);
	cube7 = Primitive::Create(Primitive::Type::Cube, "Cube7", false);
	cube7->SetTransform(Vector3{ -1, 0, 12.5f }, Vector3::zero, Vector3{ 0.2f, 0.01f, 3 });
	cube7->transform->SetParent(roadEntity->transform);
	cube8 = Primitive::Create(Primitive::Type::Cube, "Cube8", false);
	cube8->SetTransform(Vector3{ 1, 0, 17.5f }, Vector3::zero, Vector3{ 0.2f, 0.01f, 3 });
	cube8->transform->SetParent(roadEntity->transform);
	cube9 = Primitive::Create(Primitive::Type::Cube, "Cube9", false);
	cube9->SetTransform(Vector3{ -1, 0, 17.5f }, Vector3::zero, Vector3{ 0.2f, 0.01f, 3 });
	cube9->transform->SetParent(roadEntity->transform);
	
	Entity* env;
	if (Math::Random::GetRandom01() < 0.3f) {
		env = Primitive::Create(Primitive::Type::Cube, "env", false);
		env->SetTransform(Vector3{ -10, 1, 5 }, Vector3::zero, Vector3{ 1, 2, 1 });
		env->transform->SetParent(roadEntity->transform);
	}
	if (Math::Random::GetRandom01() < 0.3f) {
		env = Primitive::Create(Primitive::Type::Cube, "env", false);
		env->SetTransform(Vector3{ 10, 1, 15 }, Vector3::zero, Vector3{ 1, 2, 1 });
		env->transform->SetParent(roadEntity->transform);
	}

	roadEntity->transform->SetWorldPos(pos);
	
	return roadEntity;
}

void MainScene::OnUnload() {
	// Anything you might need to do on the level unloading
	// Entity's will be destructed/destroyed on actual level unload
}
