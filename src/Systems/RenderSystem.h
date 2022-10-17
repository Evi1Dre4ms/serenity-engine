#pragma once
#include <iostream>
#include "Scene/Components.h"
#include "Engine/ECS/EntityManager.h"

class RenderSystem
{
public:
    RenderSystem(ecs::EntityManager& entityManager) : mEntityManager(entityManager)
    {
    }

    void update(float dt)
    {
        for (auto [entity, components] : mEntityManager.getEntitySet<Transform>())
        {
            // auto [transform] = mEntityManager.getComponents<Transform>(entity);
            // position.x += velocity.x * dt;
            // position.y += velocity.y * dt;

            std::cout << (int)entity << std::endl;
        }
    }

private:
    ecs::EntityManager& mEntityManager;
};