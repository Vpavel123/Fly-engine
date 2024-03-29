#pragma once
#include <map>
#include <vector>
#include "ecsEntity.h"
#include "ecsEntityManager.h"

class ecsFilter
{
    struct DelayedOp
    {
    public:
         bool IsAdd;
         ecsEntity Entity;
    };

public:

private:
    std::vector<DelayedOp> _delayedOps;
    int _delayedOpsCount;
protected:
     std::vector<ecsEntity> Entities;
     std::map<int, int> EntitiesMap;
     int EntitiesCount;
     int LockCount;
     int EntitiesCacheSize;
     std::vector<int> IncludedTypeIndices;
     std::vector<int> ExcludedTypeIndices;

     ecsFilter(ecsEntityManager manager);
     virtual void load() = 0;
};

template <typename Inc1>
class EcsFilter : public ecsFilter
{
private:
    std::vector<int> _get1;
    bool _allow1;
    std::vector<Inc1> _pool1Items;
public:
    Inc1& Get1(int &idx)
    {
        return &_pool1Items[_get1[idx]];
    }
protected:
    EcsFilter(ecsEntityManager _manager) : ecsFilter(_manager)
    {
        _allow1 = !EcsComponentType<Inc1>.IsIgnoreInFilter;
        _pool1 = world.GetPool<Inc1>();
        _pool1.AddResizeListener(this);
        _pool1Items = _pool1.Items;
        _get1 = _allow1 ? new int[EntitiesCacheSize] : null;
        IncludedTypeIndices = new[] {
            EcsComponentType<Inc1>.TypeIndex
        };
        IncludedTypes = new[] {
            EcsComponentType<Inc1>.Type
        };
    }
};