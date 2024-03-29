#include <math.h>
#include "Transform.h"
#include <glm/glm.hpp>

glm::mat4 Transform::UpdateModel()
{
	glm::mat4 model;
	model = glm::translate(model, position);
	model = glm::rotate(model, -90.0f, rotation);
	model = glm::scale(model, scale);
	return model;
}