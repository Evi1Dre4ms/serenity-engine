#pragma once
#include <memory>
#include <GLFW/glfw3.h>

class Input;

namespace st
{
    class Window;

    class InputManager
    {
        private:
            Input* mCurrentInput = nullptr;

            Window& mWindow;

        public:

            InputManager(Window& window);

            void handleInput();

            void setInput(Input* input);

            static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
            static void MouseCallback(GLFWwindow* window, int button, int action, int mods);
            static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
            static void KeyModCallback(GLFWwindow* window, unsigned int key, int mods);
    };
}