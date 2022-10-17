#include <iostream>
#include <chrono>
#include "fmt/core.h"

#include "Engine/Engine.h"
#include "Engine/Window.h"
#include "Scene/Scene.h"

int main()
{
	st::Engine engine;

    st::Scene s;
    s;

    engine.init();
    engine.update();

    // st::Window w;
    // w.create();
    // w.update();

	// constexpr auto nbEntities = std::size_t(10000);
    // constexpr auto nbUpdates = std::size_t(100);
    // auto manager = EntityManager<ComponentCount, SystemCount>();
    // manager.registerComponent<Position>();
    // manager.registerComponent<Velocity>();
    // auto system = manager.createSystem<PhysicsSystem>(manager);
    // manager.reserve(nbEntities);
    // for (auto i = std::size_t(0); i < nbEntities; ++i)
    // {
    //     auto entity = manager.createEntity();
    //     manager.addComponent<Position>(entity, 0.0f, 0.0f);
    //     manager.addComponent<Velocity>(entity, 1.0f, 1.0f);
    // }
    // auto prevTime = std::chrono::system_clock::now();
    // for (auto i = std::size_t(0); i < nbUpdates; ++i)
    // {
    //     auto time = std::chrono::system_clock::now();
    //     auto dt = std::chrono::duration<float>(time - prevTime).count();
    //     prevTime = time;
    //     system->update(dt);
    // }

	

	return 0;
}