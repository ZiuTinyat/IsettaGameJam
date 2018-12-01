#pragma once
#include <IsettaEngine.h>
using namespace Isetta;

DEFINE_COMPONENT(GameManager, Component, false)
private:
	const int blockMaintainNumber = 10;
	const float blockLength = 20;
	float blockOffset = 0;
	std::queue<Entity*> blockQueue;

	void GenerateBlock();

public:
	Entity * boost0, *boost1;
	float carSpeed = 0;
	float carMaxSpeed = 25;
	float carAcc = 8;
	float carDecc = 15;

	// A component MUST have a default constructor
	GameManager() = default;

	// Awake is called once, immediately when the component is first created and enabled
	//void Awake() override;
	// Start is called once, on the first update frame after the component is created and enabled
	void Start() override;
	// OnEnable is called immediately each time the component becomes active, including after creation
	//void OnEnable() override;
	// OnDisable is called immediately each time the component becomes inactive
	//void OnDisable() override;
	// Update is called each frame (variable delta time)
	void Update() override;
	// GuiUpdate is called each frame (variable delta time), GUI can only be called in GuiUpdate
	//void GuiUpdate() override;
	// LateUpdate is called each frame (variable delta time)
	//void LateUpdate() override;
	// FixedUpdate is called on fixed time (constant delta time)
	//void FixedUpdate() override;
	// OnDestroy is called once when the component is destroyed
	//void OnDestroy() override;

	DEFINE_COMPONENT_END(GameManager, Component)