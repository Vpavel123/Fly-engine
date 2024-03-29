#include "CameraViewSystem.h"
#include <iostream>
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

CameraViewSystem::CameraViewSystem() 
{

}

void CameraViewSystem::Run()
{
}

//void CameraViewSystem::Run()
//{
	//float prFov = 0.0f;
	//float pow = 0.0f;

	//float yaw = -90.0f;	// Yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right (due to how Eular angles work) so we initially rotate a bit to the left.
	//float pitch = 0.0f;
	//float lastX = Screen::width() / 2.0;
	//float lastY = Screen::height() / 2.0;
	//double xpos;
	//double ypos;

	//if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	//{
	//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	//	glfwGetCursorPos(window, &xpos, &ypos);

	//	float xoffset = xpos - lastX;
	//	float yoffset = lastY - ypos; // Reversed since y-coordinates go from bottom to left
	//	lastX = xpos;
	//	lastY = ypos;

	//	xoffset *= sensitivity;
	//	yoffset *= sensitivity;

	//	yaw += xoffset;
	//	pitch += yoffset;

	//	// Make sure that when pitch is out of bounds, screen doesn't get flipped
	//	if (pitch > 89.0f) {
	//		pitch = 89.0f;
	//	}
	//	if (pitch < -89.0f) {
	//		pitch = -89.0f;
	//	}

	//	glm::vec3 front;
	//	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	//	front.y = sin(glm::radians(pitch));
	//	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	//	cameraSystem->cam->cameraFront = glm::normalize(front);
	//}


	//if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_3) == GLFW_RELEASE)
	//{
	//	prFov = cameraSystem->cam->FOV;
	//	pow = 1;
	//}

	//if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_3) == GLFW_PRESS)
	//{
	//	pow += 0.01f;
	//	pow = std::min(pow, 2.0f);
	//	cameraSystem->cam->FOV -= (float)std::pow(1.0f, pow);
	//	cameraSystem->cam->FOV = std::max(cameraSystem->cam->FOV, 0.5f);
	//}
	//else
	//{
	//	cameraSystem->cam->FOV = prFov;
	//} 

	//	if (firstClick)
	//	{
	//		glfwSetCursorPos(window, (double)(Screen::width() / 2), (double)(Screen::height() / 2));
	//		firstClick = false;
	//	}
	//	double posX;
	//	double posY;
	//	glfwGetCursorPos(window, &posX, &posY);
	//	float rotX = sensitivity * (float)(posY - (Screen::height() / 2)) / Screen::width();
	//	float rotY = sensitivity * (float)(posX - (Screen::width() / 2)) / Screen::height();
	//	glm::vec3 newcameraFront = glm::rotate(cameraSystem->cam->cameraFront, glm::radians(-rotX), glm::normalize(glm::cross(cameraSystem->cam->cameraFront, cameraSystem->cam->cameraUp)));
	//	if (glm::abs(glm::angle(newcameraFront, cameraSystem->cam->cameraUp) - glm::radians(90.0f)) <= glm::radians(85.0f))
	//	{
	//		cameraSystem->cam->cameraFront = newcameraFront;
	//	}
	//	cameraSystem->cam->cameraFront = glm::rotate(cameraSystem->cam->cameraFront, glm::radians(-rotY), cameraSystem->cam->cameraUp);
	//	glfwSetCursorPos(window, (double)(Screen::width() / 2), (double)(Screen::height() / 2));
	//}
	//else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	//{
	//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	//	firstClick = true;
	//}

	//if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_3) == GLFW_RELEASE)
	//{
	//	prFov = cameraSystem->cam->FOV;
	//	pow = 1;
	//}

	//if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_3) == GLFW_PRESS)
	//{
	//	pow += 0.01f;
	//	pow = std::min(pow, 2.0f);
	//	cameraSystem->cam->FOV -= (float)std::pow(1.0f, pow);
	//	cameraSystem->cam->FOV = std::max(cameraSystem->cam->FOV, 0.5f);
	//}
	//else
	//{
	//	cameraSystem->cam->FOV = prFov;
	//}
//}