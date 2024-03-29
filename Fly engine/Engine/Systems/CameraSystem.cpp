#include "CameraSystem.h"
#include "../Graphics/Screen.h"
#include <GLFW/glfw3.h>
#include <iostream>

CameraSystem::CameraSystem()
{
	cam = new (Camera);
}

void CameraSystem::Run()
{
	BuildProjMatrix(*cam);
	BuildOthroMatrix(*cam);
	BuildViewMatrix(*cam);
}

void CameraSystem::BuildProjMatrix(Camera& cam)
{
	cam.Projection = glm::perspective(glm::radians(cam.FOV), (float)Screen::width() / (float)Screen::height(), cam.Near, cam.Far);
}

void CameraSystem::BuildOthroMatrix(Camera& cam)
{
	cam.Othro = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
}

void CameraSystem::BuildViewMatrix(Camera& cam)
{
	cam.View = glm::lookAt(cam.cameraPosition, cam.cameraPosition + cam.cameraFront, cam.cameraUp);
}
