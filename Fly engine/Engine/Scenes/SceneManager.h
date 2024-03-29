#pragma once
#include "Scene.h"

class SceneManager
{
public:
    SceneManager();
    Scene *Current;
    void Load(Scene *scene);
};