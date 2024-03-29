#pragma once
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include<glm/gtc/matrix_transform.hpp>
#include <glm/detail/type_vec.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include "../Graphics/Screen.h"
#include "../../Engine/Systems/ECS/ecsSystem.h"

class CameraViewSystem : public IEcsRunSystem
{
public:
	float sensitivity = 0.001f;
	bool firstClick = true;
	CameraViewSystem();
	virtual void Run() override;
};