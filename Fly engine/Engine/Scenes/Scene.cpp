#include "Scene.h"

void Scene::Load()
{
	OnLoadContent();
	OnConfigureUpdate(ecsupdateSystems);
	ConfigureRenderPipeline(renderPipeline);
	BuildEntitis();
	InitSystems();
}

Scene::Scene()
{
	content = ResourceDictionary();
	manager = ecsEntityManager();
	ecsupdateSystems = ecsSystems(&manager);
	renderPipeline = ecsSystems(&manager);
}

void Scene::UpdateSystems()
{
	ecsupdateSystems.Run();
}

void Scene::DrawSystems()
{
	renderPipeline.Run();
}

void Scene::InitSystems() 
{
	ecsupdateSystems.Init();
	renderPipeline.Init();
}

ResourceDictionary Scene::content;