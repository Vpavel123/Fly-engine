#pragma once
#include "ECS.h"
#include "ecsComponent.h"

struct CounterComponent : ecsComponent
{
    float counter;
    void update(float mFT) override
    {
        counter += mFT;
        std::cout << counter << std::endl;
    }
};

struct KillComponent : ecsComponent
{
    CounterComponent* cCounter{ nullptr };

    // Instead of passing the entity as a parameter in the constructor,
    // we can now override the `init()` method and get the counter
    // component with our new methods.
    void init() override
    {
        cCounter = &m_entity->getComponent<CounterComponent>();
    }

    void update(float mFT) override
    {
        if (cCounter->counter >= 100) m_entity->destroy();
    }
};