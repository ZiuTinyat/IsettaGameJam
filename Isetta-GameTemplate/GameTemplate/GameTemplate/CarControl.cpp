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
	xDimLinearity = 0.2;
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
		xDimLinearity = 0.2f;
		else		
			xDimLinearity = 0.2f;

	});

	rightRelease= Input::RegisterKeyReleaseCallback(KeyCode::RIGHT_ARROW, [&]() {
		pressingRight = false;
		if (!pressingLeft)
			xDimLinearity = 0.2f;
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
	if (drunkTimeLeft <= 0.f && Math::Random::GetRandom01() < 0.02f)
	{
		drunkTimeLeft = 0.3f;
		if (Math::Random::GetRandom01() > 0.5f)
			drunkDirection = LeftOrRight::Left;
		else
			drunkDirection = LeftOrRight::Right;
	}
	if (drunkTimeLeft > 0.f)
	{
		drunkTimeLeft -= Time::GetFixedDeltaTime();
		if (drunkTimeLeft <= 0.f)
		{
			xDimLinearity = 0.2f;
			pressingLeft = false;
			pressingRight = false;
		}
		switch (drunkDirection)
		{
		case LeftOrRight::Left:
			if(!pressingRight)
			pressingLeft = true;
			break;

		case LeftOrRight::Right:
			if (!pressingLeft)
			pressingRight = true;
			break;
		}
	}
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
		if (angle > 0.4f) angle -= powerCurve.GetValue(Math::Util::Abs(angle)/angleLimit)*restraightSpeed;
		else if (angle < -0.4f) angle += powerCurve.GetValue(Math::Util::Abs(angle) / angleLimit)*restraightSpeed;
		else angle = 0;
	}

	if (angle > angleLimit) angle = angleLimit;
	else if (angle < -angleLimit) angle = -angleLimit;

	transform->SetLocalRot(Vector3{ 0, angle, 0 });

	float horizontalProjection = Math::Util::Sin(angle/180.f * Math::Util::PI) * horizontalSpeed * (1.f- gm->carSpeed / gm->carMaxSpeed*.2f);

	Vector3 pos = transform->GetWorldPos();

	transform->SetWorldPos(Vector3(pos.x + horizontalProjection, pos.y, pos.z));

}
