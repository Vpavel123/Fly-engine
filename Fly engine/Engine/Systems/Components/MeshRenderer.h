#pragma once
#include "../../Graphics/Geometry/Mesh.h"
#include "../../Graphics/Materials/Material.h"
#include "../../Systems/ECS/ecsComponent.h"

struct MeshRenderer : public ecsComponent
{
public:
	Mesh mesh;
	Material* material;
};