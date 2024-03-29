#pragma once
#include "Scene.h"
#include "../Systems/ECS/ecsEntityList.h"
#include "../Graphics/Geometry/Mesh.h"
#include "../Systems/CameraSystem.h"
#include "../Systems/ECS/ecsSystem.h"
#include "../Inputs/Input.h"

class MainScene : public Scene
{
public:
	struct MeshRenderer* rend;
	struct Transform* transform;
	ecsEntityList entityList;
	CameraSystem camera;
	Input* input;
	MainScene();
	void OnLoadContent() override;
	void BuildEntitis() override;
	void OnConfigureUpdate(ecsSystems systems) override;
	void ConfigureRenderPipeline(ecsSystems pipeline) override;
/// <summary>
/// properties
/// </summary>
__declspec(property(get=get_Value, put=put_Value)) ecsSystems _systems;
private:
	ecsSystems systems;
public:
	ecsSystems get_Value()
	{
		return systems;    
	}
	void put_Value(ecsSystems value)
	{
		systems = value;   
	}
};