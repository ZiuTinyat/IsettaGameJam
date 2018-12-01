// IsettaCore not necessarily needed, holds a number of useful header files
#include <IsettaEngine.h>

#include "ToResourcesView.h"
#include "ResourcesViewLevel.h"

using namespace Isetta;
using namespace Math;

std::string ToResourcesView::previousLevelName;

void ToResourcesView::Update() {
	if (Input::IsKeyPressed(KeyCode::ESCAPE))
		Application::Exit();
}

void ToResourcesView::OnEnable()
{
	handleSpace = Input::RegisterKeyReleaseCallback(KeyCode::SPACE, []() {
		std::string currentLevelName = LevelManager::Instance().loadedLevel->GetName().c_str();
		if (currentLevelName != "ResourcesViewLevel")
		{
			previousLevelName = currentLevelName;
			LevelManager::Instance().LoadLevel("ResourcesViewLevel");
		}
		else
		{
			LevelManager::Instance().LoadLevel(previousLevelName);
		}
	});
}

void ToResourcesView::OnDisable()
{
	Isetta::Input::UnregisterKeyPressCallback(KeyCode::SPACE, handleSpace);
}
