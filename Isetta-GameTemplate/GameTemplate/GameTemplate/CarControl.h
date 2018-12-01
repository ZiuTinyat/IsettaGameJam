#pragma once
#include <IsettaEngine.h>
#include "PowerCurve.h"
using namespace Isetta;

DEFINE_COMPONENT(CarControl, Component, false)
private:
	// Private variables of your component
	float angle;
	float angleSpeed;
	float angleLimit;
	float turningSpeed = 10;
	float linearity = 1.3f;
	float restraightSpeed = 2;
	float horizontalSpeed = 0.1f;

	U64 leftSteering;
	U64 rightSteering;
	U64 leftRelease;
	U64 rightRelease;

	bool pressingLeft;
	bool pressingRight;

	float xDimLinearity;
	PowerCurve powerCurve;
public:
	Entity * boost0, *boost1;

	// A component MUST have a default constructor
	CarControl() :powerCurve(linearity, 10) {};

	// Awake is called once, immediately when the component is first created and enabled
	//void Awake() override;
	// Start is called once, on the first update frame after the component is created and enabled
	void Start() override;
	// OnEnable is called immediately each time the component becomes active, including after creation
	void OnEnable() override;
	// OnDisable is called immediately each time the component becomes inactive
	void OnDisable() override;
	// Update is called each frame (variable delta time)
	//void Update() override;
	// GuiUpdate is called each frame (variable delta time), GUI can only be called in GuiUpdate
	//void GuiUpdate() override;
	// LateUpdate is called each frame (variable delta time)
	//void LateUpdate() override;
	// FixedUpdate is called on fixed time (constant delta time)
	void FixedUpdate() override;
	// OnDestroy is called once when the component is destroyed
	//void OnDestroy() override;

	DEFINE_COMPONENT_END(CarControl, Component)