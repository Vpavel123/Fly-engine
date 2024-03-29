#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include "../Systems/ECS/ecsSystem.h"
#include "../Systems/CameraSystem.h"
#include "../Systems/Components/Transform.h"
#include "../Systems/MoveSystem.h"
#include "../Systems/CameraViewSystem.h"

class Input : public IEcsRunSystem
{
public:
    std::vector<Input*> device;
    Input();
    Input(GLFWwindow* _window, CameraSystem* _cameraSystem, Transform* _transform);
    template<typename T>
    void GetDevice(T *t);
    virtual void Run() override;
    //virtual void Run(GLFWwindow* window, CameraSystem* cameraSystem, Transform* transform);
private:
    MoveSystem* moveSystem;
    CameraViewSystem* cameraViewSystem;
    GLFWwindow* window;
    CameraSystem* cameraSystem;
    Transform* transform;
};

template<typename T>
void Input::GetDevice(T* t)
{
    device.push_back(t);
}