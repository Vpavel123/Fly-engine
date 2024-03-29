#include "SceneManager.h"

SceneManager::SceneManager()
{

}

void SceneManager::Load(Scene *scene)
{
	Current = scene;
	Current->Load();
}