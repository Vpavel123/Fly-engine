#include "Input.h"

Input::Input()
{
}

Input::Input(GLFWwindow* _window, CameraSystem* _cameraSystem, Transform* _transform)
{
	window = _window;
	cameraSystem = _cameraSystem;
	transform = _transform;
}

void Input::Run()
{
	moveSystem = new MoveSystem();
	moveSystem->Run(window, cameraSystem, transform);
	cameraViewSystem = new CameraViewSystem();
	cameraViewSystem->Run(window, cameraSystem, transform);
}
