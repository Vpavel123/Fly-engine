#pragma once
#include <GLFW/glfw3.h>
#include <glm/detail/type_vec.hpp>
#include "../Systems/Components/Transform.h"
#include "../Systems/Components/Camera.h"

class KeyboardState
{
public:
	KeyboardState();
	float speedMul = 0.01f;
	struct Camera* cam;
	struct Transform* transform;
	void BindKeyGLFWwindow(GLFWwindow* window);
};