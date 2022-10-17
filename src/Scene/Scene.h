#pragma once
#include <memory>
#include "Systems/RenderSystem.h"

namespace ecs
{
    class EntityManager;
}

namespace st
{
    

    class Scene
    {
        private:

            std::shared_ptr<ecs::EntityManager> manager;

        public:
            Scene();

            int x = 123;

    };

}