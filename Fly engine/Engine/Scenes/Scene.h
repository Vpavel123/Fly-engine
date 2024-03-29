#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Systems/ECS/ecsSystem.h"
#include "../Resources/ResourceDictionary.h"
#include "../Systems/ECS/ecsEntityManager.h"

class Scene
{
public:
	static ResourceDictionary content;
	void Load();
	virtual void ConfigureRenderPipeline(ecsSystems pipeline) = 0;
	virtual void OnConfigureUpdate(ecsSystems systems) = 0;
	virtual void OnLoadContent() = 0;
	virtual void BuildEntitis() = 0;
	void UpdateSystems();
	void DrawSystems();
	void InitSystems();
	ecsSystems renderPipeline;
	ecsSystems ecsupdateSystems;
protected:
	Scene();
	ecsEntityManager manager;
private:
};