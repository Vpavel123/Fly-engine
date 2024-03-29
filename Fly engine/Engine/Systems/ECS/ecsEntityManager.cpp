#include "ecsEntityManager.h"
#include <memory>
#include <algorithm>

void ecsEntityManager::draw()
{
	for (auto& entity : entities)
		entity->draw();
}

void ecsEntityManager::update(float mFT)
{
	for (auto& entity : entities)
		entity->update(mFT);
}

void ecsEntityManager::refresh()
{


	entities.erase(std::remove_if(std::begin(entities), std::end(entities), [](const std::unique_ptr<ecsEntity>& Entity) 
	{
		return !Entity->isActive();
	}), std::end(entities));
}

ecsEntity& ecsEntityManager::addEntity()
{
	ecsEntity* entity{ new ecsEntity{} };
	std::unique_ptr<ecsEntity> uniquePtr{entity};
	entities.emplace_back(std::move(uniquePtr));
	return *entity;
}



void ecsEntityManager::eraseEntity(ecsEntity* entity)
{
}

ecsEntity* ecsEntityManager::cloneEntity(ecsEntity* entity)
{
	return nullptr;
}

void ecsEntityManager::addToGroup(ecsEntity* mEntity, Group mGroup)
{
	groupedEntities[mGroup].emplace_back(mEntity);
}

std::vector<ecsEntity*>& ecsEntityManager::getEntitiesByGroup(Group mGroup)
{
	return groupedEntities[mGroup];
}
