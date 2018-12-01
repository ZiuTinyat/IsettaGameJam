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
	if (Input::IsKeyPressed(KeyCode::SPACE)) { // BOOSTING
		carMaxSpeed = 45;
		carAcc = 20;
		Vector3 scale = boost0->transform->GetLocalScale();
		scale.z = Math::Util::Lerp(0, 2.5f, (carSpeed - 20) / (45 - 20));
		boost0->transform->SetLocalScale(scale);
		boost1->transform->SetLocalScale(scale);
	}
	else {
		carMaxSpeed = 25;
		carAcc = 8;
		
	}

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
