#pragma once
#include <GLFW/glfw3.h>
#include <glm/detail/type_vec.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include "../../Engine/Systems/ECS/ecsSystem.h"

class MoveSystem : public IEcsRunSystem
{
public:
	MoveSystem();
	float speedMul = 0.01f;
	virtual void Run() override;
};