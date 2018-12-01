#pragma once
#include <IsettaEngine.h>
using namespace Isetta;

DEFINE_COMPONENT(ToResourcesView, Component, false)
private:
	// Private variables of your component
	U64 handleSpace;
	bool previousKeyPressed = false;
public:
	// A component MUST have a default constructor
	void loadScene();

	ToResourcesView() = default;
	static std::string previousLevelName;
	void OnEnable() override;
	void OnDisable() override;
	void Update() override;
	DEFINE_COMPONENT_END(ToResourcesView, Component)