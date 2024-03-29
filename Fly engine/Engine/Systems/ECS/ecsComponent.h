#pragma once

class ecsEntity;

struct ecsComponent
{
public:
    ecsEntity* m_entity;

    ecsComponent() = default;
    virtual ~ecsComponent() = default;

    virtual void init() {  }
    virtual void draw() {}
    virtual void update(float mFT) {}
};