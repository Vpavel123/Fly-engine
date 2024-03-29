#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Camera
{
public: 
    glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 80.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    float FOV;
    float Near;
    float Far;
    glm::mat4 View;
    glm::mat4 Projection;
    glm::mat4 Othro;
};