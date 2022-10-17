#pragma once
#include <memory>
#include <vector>

#include "Window.h"
#include "InputManager.h"
#include "CameraManager.h"

namespace st
{
    class Engine
    {
        private:

            Window mWindow;
            InputManager mInputManager;
            CameraManager mCameraManager;

        public:
            Engine();

            int init();

            int update();

            void createScene();

    };


}