// IsettaCore not necessarily needed, holds a number of useful header files
#include <IsettaEngine.h>

#include "MyScript.h"

using namespace Isetta;
using namespace Math;

void MyScript::Start() {
	
}

void MyScript::OnEnable() {
	handleEscPress = Input::RegisterKeyPressCallback(
		KeyCode::SPACE, []() { LevelManager::Instance().LoadLevel("MainScene"); });
}

void MyScript::OnDisable() {
	Isetta::Input::UnregisterKeyPressCallback(KeyCode::ESCAPE, handleEscPress);
}

void MyScript::Update() {
	//if (Input::IsKeyPressed(KeyCode::ESCAPE)) {
		
	//}
	transform->RotateLocal(Vector3::up * Time::GetDeltaTime() * 60.0f);
}