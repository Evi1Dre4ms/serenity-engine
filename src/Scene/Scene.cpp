#include "Scene.h"
#include "Engine/ECS/EntityManager.h"

st::Scene::Scene() : manager(new ecs::EntityManager())
{
    constexpr auto nbEntities = std::size_t(10);
    constexpr auto nbUpdates = std::size_t(100);
    manager->reserve(nbEntities);

    auto system = RenderSystem(*manager);

    for (auto i = std::size_t(0); i < nbEntities; ++i)
    {
        auto entity = manager->createEntity();
        manager->addComponent<Transform>(entity);
    }

    system.update(0);


}