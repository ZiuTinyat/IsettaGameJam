// IsettaCore not necessarily needed, holds a number of useful header files
#include <IsettaEngine.h>

#include "CarControl.h"

using namespace Isetta;
using namespace Math;

void CarControl::Start() {
	angle = 0;
	angleSpeed = 40;
	angleLimit = 10;
}

void CarControl::Update() {
	float move = Time::GetDeltaTime() * angleSpeed;
	if (Input::IsKeyPressed(KeyCode::LEFT_ARROW)) {
		angle += move;
	} else if (Input::IsKeyPressed(KeyCode::RIGHT_ARROW)) {
		angle -= move;
	}
	else {
		// To zero
		if (angle > 0.01f) angle -= move;
		else if (angle < -0.01f) angle += move;
		else angle = 0;
	}

	if (angle > angleLimit) angle = angleLimit;
	else if (angle < -angleLimit) angle = -angleLimit;

	transform->SetLocalRot(Vector3{ 0, angle, 0 });
}