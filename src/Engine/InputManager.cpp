#include "InputManager.h"
#include <fmt/core.h>

#include "Window.h"
#include "Scene/Components.h"

void st::InputManager::handleInput()
{
    if (mCurrentInput == nullptr)
        return;

    // TODO: Bindings
    glfwGetKey(mWindow.window, GLFW_KEY_W);
    glfwGetKey(mWindow.window, GLFW_KEY_A);
    glfwGetKey(mWindow.window, GLFW_KEY_S);
    glfwGetKey(mWindow.window, GLFW_KEY_D);
}

void st::InputManager::setInput(Input* input)
{
    mCurrentInput = input;
}

st::InputManager::InputManager(Window& window) : mWindow(window) {}

// Callbacks
void st::InputManager::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    fmt::print("Key: [{}] Action: [{}]\n", key, (bool)action);
}

void st::InputManager::MouseCallback(GLFWwindow* window, int button, int action, int mods)
{

}

void st::InputManager::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{

}

void st::InputManager::KeyModCallback(GLFWwindow* window, unsigned int key, int mods)
{

}
