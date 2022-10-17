#pragma once
#include <iostream>
#include "Scene/Components.h"
#include "Engine/ECS/EntityManager.h"

// class MovementSystem : public ecs::System<ComponentCount, SystemCount>
// {
// public:
//     MovementSystem(ecs::EntityManager<ComponentCount, SystemCount>& entityManager) : mEntityManager(entityManager) {}

//     void update(float dt)
//     {
//         for (const auto& entity : getManagedEntities())
//         {
//             auto [input, camera, transform] = mEntityManager.getComponents<Input, Camera, Transform>(entity);
            
//             auto W = camera.direction * (float)input.W;
//             auto S = -camera.direction * (float)input.S;
//             auto D = camera.right * (float)input.D;
//             auto A = -camera.right * (float)input.A;

//             transform.position += (W + A + S + D) * dt;
//         }
//     }

// private:
//     ecs::EntityManager<ComponentCount, SystemCount>& mEntityManager;
// };