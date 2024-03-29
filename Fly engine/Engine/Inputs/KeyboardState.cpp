#include "KeyboardState.h"

KeyboardState::KeyboardState()
{

}

void KeyboardState::BindKeyGLFWwindow(GLFWwindow* window)
{
	float speedMul = 0.01f;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		transform->position += speedMul * cam->cameraFront;
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		transform->position += speedMul * -cam->cameraFront;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		transform->position += speedMul * -glm::normalize(glm::cross(cam->cameraFront, cam->cameraUp));
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		transform->position += speedMul * glm::normalize(glm::cross(cam->cameraFront, cam->cameraUp));
	}

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}