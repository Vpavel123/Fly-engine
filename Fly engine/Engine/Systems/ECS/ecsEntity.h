#pragma once
#include <map>
#include <array>
#include <vector>
#include <memory>
#include <algorithm>
#include "ECS.h" 
#include "ecsComponent.h"

class ecsEntity
{
public:
    ecsEntity() = default;

    template <typename T>
    bool hasComponent() const
    {
        return compBitset[getComponentTypeID<T>()];
    }

    template<typename T, typename... TArgs>
    inline T& addComponent(TArgs&&... mArgs)
    {
        assert(!hasComponent<T>());
        T* comp(new T(std::forward<TArgs>(mArgs)...));
        comp->m_entity = this;
        std::unique_ptr<ecsComponent> uptr{comp};
        components.emplace_back(std::move(uptr));

        // When we add a component of type `T`, we add it to
        // the bitset and to the array.
        compList[getComponentTypeID<T>()] = comp;
        compBitset[getComponentTypeID<T>()] = true;

        // We can now call `Component::init()`:
        comp->init();

        return *comp;
    }

    template<typename T>
    inline T& getComponent() const 
    {
        assert(hasComponent<T>());
        auto ptr(compList[getComponentTypeID<T>()]);
        return *reinterpret_cast<T*>(ptr); 
    }

    //template<typename T>
    //inline T& hasComponent() const
    //{
    //    return ComponentBitset[getComponentTypeID<T>()];
    //}

    inline bool isActive() const
    {
        return active;
    }

    inline void destroy()
    {
        active = false;
    }

    inline void draw()
    {
        for (auto& comp : components)
            comp->draw();
    }

    inline void update(float mFT)
    {
        for (auto& comp : components)
            comp->update(mFT);
    }

private:
    bool active = true;
    ComponentList compList;
    ComponentBitset compBitset;
    GroupBitset groupBitset;
    std::vector<std::unique_ptr<ecsComponent>> components;
};