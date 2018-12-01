// IsettaCore not necessarily needed, holds a number of useful header files
#include <IsettaEngine.h>

#include "CarControl.h"

using namespace Isetta;
using namespace Math;

void CarControl::Start() {
	angle = 0;
	angleSpeed = 5;
	angleLimit = 15;
	turningSpeed;
}

void CarControl::OnEnable()
{
	leftSteering = Input::RegisterKeyPressCallback(KeyCode::LEFT_ARROW, [&]() {
		pressingLeft = true;
		pressingRight = false;
	});

	leftRelease = Input::RegisterKeyReleaseCallback(KeyCode::LEFT_ARROW, [&]() {
		pressingLeft = false;
		if (!pressingRight)
		xDimLinearity = 0.f;
		else		
			xDimLinearity = 0.2f;

	});

	rightRelease= Input::RegisterKeyReleaseCallback(KeyCode::RIGHT_ARROW, [&]() {
		pressingRight = false;
		if (!pressingLeft)
			xDimLinearity = 0.f;
		else
			xDimLinearity = 0.2f;
	});

	rightSteering = Input::RegisterKeyPressCallback(KeyCode::RIGHT_ARROW, [&]() {
		pressingRight = true;
		pressingLeft = false;
	});
}

void CarControl::OnDisable()
{
	Input::UnregisterKeyPressCallback(KeyCode::LEFT_ARROW, leftSteering);
	Input::UnregisterKeyPressCallback(KeyCode::RIGHT_ARROW, rightSteering);
	Input::UnregisterKeyReleaseCallback(KeyCode::LEFT_ARROW, leftRelease);
	Input::UnregisterKeyReleaseCallback(KeyCode::RIGHT_ARROW, rightRelease);
}

void CarControl::FixedUpdate() {
	float move;
	if(pressingLeft || pressingRight)
	xDimLinearity += Time::GetDeltaTime() * turningSpeed;
	xDimLinearity = Math::Util::Clamp01(xDimLinearity);
	move = powerCurve.GetValue(xDimLinearity) * angleSpeed;
	if (pressingLeft) {
		angle += move;
	} else if (pressingRight) {
		angle -= move;
	}
	else {
		// To zero
		if (angle > 0.4f) angle -= powerCurve.GetValue(0.2f) * angleSpeed;
		else if (angle < -0.4f) angle += powerCurve.GetValue(0.2f) * angleSpeed;
		else angle = 0;
	}

	if (angle > angleLimit) angle = angleLimit;
	else if (angle < -angleLimit) angle = -angleLimit;

	transform->SetLocalRot(Vector3{ 0, angle, 0 });
}
