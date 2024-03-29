#include "MoveSystem.h"
#include "../Graphics/Screen.h"
#include <iostream>

MoveSystem::MoveSystem()
{
}

void MoveSystem::Run()
{
	std::cout << "IDI nAhyI" << std::endl;
	/*float speedMul = 0.01f;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		cameraSystem->cam->cameraPosition += 0.1f * cameraSystem->cam->cameraFront;
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		cameraSystem->cam->cameraPosition += 0.1f * -cameraSystem->cam->cameraFront;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		cameraSystem->cam->cameraPosition += speedMul * -glm::normalize(glm::cross(cameraSystem->cam->cameraFront, cameraSystem->cam->cameraUp));
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		cameraSystem->cam->cameraPosition += speedMul * glm::normalize(glm::cross(cameraSystem->cam->cameraFront, cameraSystem->cam->cameraUp));
	}

	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		cameraSystem->cam->cameraPosition += speedMul * cameraSystem->cam->cameraUp;
	}

	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
	{
		cameraSystem->cam->cameraPosition += speedMul * -cameraSystem->cam->cameraUp;
	}

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		speedMul = 0.04f;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
	{
		speedMul = 0.01f;
	}*/
}