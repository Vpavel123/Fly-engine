#pragma once

#include <array>
#include <vector>
#include <memory>
#include <algorithm>
#include "ecsEntity.h"

class ecsEntity;

class ecsEntityManager
{
public:
    struct EcsWorldConfig
    {
    public:
        /// <summary>
        /// World.Entities cache size.
        /// </summary>
        int WorldEntitiesCacheSize;
        /// <summary>
        /// World.Filters cache size.
        /// </summary>
        int WorldFiltersCacheSize;
        /// <summary>
        /// World.ComponentPools cache size.
        /// </summary>
        int WorldComponentPoolsCacheSize;
        /// <summary>
        /// Entity.Components cache size (not doubled).
        /// </summary>
        int EntityComponentsCacheSize;
        /// <summary>
        /// Filter.Entities cache size.
        /// </summary>
        int FilterEntitiesCacheSize;
        /// <summary>
        /// World.Entities default cache size.
        /// </summary>
        const int DefaultWorldEntitiesCacheSize = 1024;
        /// <summary>
        /// World.Filters default cache size.
        /// </summary>
        const int DefaultWorldFiltersCacheSize = 128;
        /// <summary>
        /// World.ComponentPools default cache size.
        /// </summary>
        const int DefaultWorldComponentPoolsCacheSize = 512;
        /// <summary>
        /// Entity.Components default cache size (not doubled).
        /// </summary>
        static const int DefaultEntityComponentsCacheSize = 8;
        /// <summary>
        /// Filter.Entities default cache size.
        /// </summary>
        const int DefaultFilterEntitiesCacheSize = 256;
    };

	void draw();
	void update(float mFT);
	void refresh();

	ecsEntity& addEntity();
	void eraseEntity(ecsEntity* entity);
	ecsEntity* cloneEntity(ecsEntity* entity);
	void addToGroup(ecsEntity* mEntity, Group mGroup);
	std::vector<ecsEntity*>& getEntitiesByGroup(Group mGroup);
    EcsWorldConfig* Config;
	std::vector<std::unique_ptr<ecsEntity>> entities;
private:
	std::array<std::vector<ecsEntity*>, maxGroups> groupedEntities;
};