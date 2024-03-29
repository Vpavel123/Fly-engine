#pragma once
#include <iostream>
#include "../Components/MeshRenderer.h"
#include "../../Systems/CameraSystem.h"
#include "../../Scenes/MainScene.h"
#include "../../Inputs/Input.h"
#include "../ECS/ecsSystem.h"
#include "../../Systems/MoveSystem.h"
#include "../../Systems/CameraViewSystem.h"

class MeshRendererSystem : public IEcsRunSystem, public IEcsInitSystem
{
public:
	double dArray[16] = { 0.0 };
	struct MeshRenderer* render;
	CameraSystem* cameraSystem;
	struct Transform* transform;
	MainScene* main;
	Input *input;
	MeshRendererSystem(Scene * scene);
	Scene* _scene;
	// ������������ ����� IEcsInitSystem
	virtual void Init() override;
	// ������������ ����� IEcsRunSystem
	virtual void Run() override;
};