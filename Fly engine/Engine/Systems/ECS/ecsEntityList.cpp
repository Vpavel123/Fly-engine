#include "ecsEntityList.h"

ecsEntityList::ecsEntityList()
{
}

void ecsEntityList::add(ecsEntity&& entity)
{
	List.emplace_back(std::move(entity));
}