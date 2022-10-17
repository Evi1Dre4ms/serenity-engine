#pragma once
#include <string>
#include <glm/glm.hpp>

class GLFWwindow;
class GLFWmonitor;
class GLFWvidmode;

namespace st
{
    class Window
    {
        public:
            glm::ivec2 resolution;
            glm::ivec2 maxResolution;

            bool isFullscreen = false;
            bool isFocused;

            std::string name = "Application";

            GLFWwindow*        window  = nullptr;
			GLFWmonitor*       monitor = nullptr;
			const GLFWvidmode* mode    = nullptr;

            struct GLContextParams
            {
                int major    = 3;
                int minor    = 3;
                int sampling = 4;
            }contextParams;

        public:
            void create();
            void update();

        private:
            void updateMaxResolution();

            void createWindow();
            void createGLContext();
    };
}