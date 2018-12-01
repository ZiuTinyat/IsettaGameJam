// IsettaCore not necessarily needed, holds a number of useful header files
#include <IsettaEngine.h>

#include "GameManager.h"
#include "MainScene.h"

using namespace Isetta;
using namespace Math;

void GameManager::Start() {
	Input::RegisterKeyPressCallback(KeyCode::ESCAPE, []() { Application::Exit(); });
	GenerateBlock();
	GenerateBlock();
	GenerateBlock();
	GenerateBlock();
	GenerateBlock();
}

void GameManager::Update() {
	if (-transform->GetLocalPos().z > blockOffset - 80) {
		GenerateBlock();
	}

	if (carSpeed < carMaxSpeed - 0.01f) {
		carSpeed += Time::GetDeltaTime() * carAcc;
	}
	else if (carSpeed > carMaxSpeed + 0.01f) {
		carSpeed -= Time::GetDeltaTime() * carDecc;
	}
	else {
		carSpeed = carMaxSpeed;
	}

	transform->TranslateLocal(Vector3::back * carSpeed * Time::GetDeltaTime());
}

void GameManager::GenerateBlock() {
	Entity* roadBlock = MainScene::CreateRoad();
	roadBlock->transform->SetParent(transform);
	roadBlock->transform->SetLocalPos(Vector3::forward * blockOffset);
	blockOffset += blockLength;
	blockQueue.push(roadBlock);

	if (blockQueue.size() > blockMaintainNumber) {
		Entity::Destroy(blockQueue.front());
		blockQueue.pop();
	}
}
