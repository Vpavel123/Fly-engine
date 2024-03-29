#include "ecsFilter.h"

ecsFilter::ecsFilter(ecsEntityManager manager)
{
    EntitiesCacheSize = manager.Config->DefaultFilterEntitiesCacheSize;
    Entities.resize(EntitiesCacheSize);
    //EntitiesMap = new std::map<int, int>(EntitiesCacheSize);
    _delayedOps.resize(EntitiesCacheSize);
    if (EntitiesMap.size() <= EntitiesCacheSize)
    {
        std::cout << "EntitiesMap overfloy" << std::endl;
    }
}
