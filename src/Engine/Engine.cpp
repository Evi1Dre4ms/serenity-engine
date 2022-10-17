#include "Engine.h"
#include <GLFW/glfw3.h>

#include "Systems/RenderSystem.h"

st::Engine::Engine() : mInputManager(mWindow) {}

int st::Engine::init()
{
    // Init window
    mWindow.create();

    // Init input callbacks
    glfwSetKeyCallback(mWindow.window, InputManager::KeyCallback);
    glfwSetMouseButtonCallback(mWindow.window, InputManager::MouseCallback);

    return 0;
}

int st::Engine::update()
{
    // TODO: deltaTime start

    // Handle incoming key actions
    mInputManager.handleInput();

    // TODO: Run ECS systems here

    // TODO: Render objects here

    // Poll events / swap buffer
    mWindow.update();

    //TODO: deltaTime end

    return 0;
}