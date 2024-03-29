#pragma once
#include <vector>
#include "ecsEntity.h"

class ecsEntityList
{
public:
	ecsEntityList();
	std::vector<ecsEntity> List;
	void add(ecsEntity&& entity);
};

