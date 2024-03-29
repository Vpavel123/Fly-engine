#pragma once
#include "Components/Camera.h"
#include "Components/Transform.h"
#include "ECS/ecsComponent.h"

class CameraSystem : public ecsComponent
{
public:
	CameraSystem();
	struct Camera* cam;
	struct Transform* transform;
	void Run();
private:
	void BuildProjMatrix(Camera &cam);
	void BuildOthroMatrix(Camera &cam);
	void BuildViewMatrix(Camera &cam);
};