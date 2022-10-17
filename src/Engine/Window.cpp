#include "Window.h"
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <fmt/core.h>

#ifdef __linux__ 
	#include <X11/Xlib.h>
#elif _WIN32
	#include <windows.h>
#else
	//TODO: MacOS
#endif

void st::Window::create()
{
    createWindow();
    createGLContext();
}

void st::Window::update()
{
	do{
		static double lastTime = glfwGetTime();
		double currentTime = glfwGetTime();
		// w.deltaTime = currentTime - lastTime;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
        glClearColor(glm::sin(glfwGetTime()), 0.4f, 0.3f, 1.0f);

		// Handle inputs

		/** --------------------------------
		 *  Draw all type of meshes in scene
		 *  -------------------------------- */

		//TODO: for GUI
		/** --------------------------------
		 *  -------------------------------- */

        glfwSwapBuffers(window);
		glfwPollEvents();

		lastTime = currentTime;
    } 
	while( glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
    glfwWindowShouldClose(window) == 0);
	// TODO: перед закрытием окна очищать все данные
}



void st::Window::createWindow()
{
    if (!glfwInit()) {
		fmt::print("Unable to init GLFW\n");
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, contextParams.major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, contextParams.minor);
	glfwWindowHint(GLFW_SAMPLES, contextParams.sampling);
	//glfwSwapInterval(1);

    // Update max screen resolution
    updateMaxResolution();

	if (isFullscreen) {
		window = glfwCreateWindow(maxResolution.x, maxResolution.y, name.c_str(), glfwGetPrimaryMonitor(), NULL);
	}
	else {
		window = glfwCreateWindow(resolution.x, resolution.y, name.c_str(), nullptr, nullptr);
	}

	if (window == nullptr) {
		fmt::print("Unable to create window\n");
		return;
	}

    glfwSetWindowPos(window, (maxResolution.x - resolution.x) / 2, (maxResolution.y - resolution.y) / 2);
	glfwMakeContextCurrent(window);
}

void st::Window::createGLContext()
{
    // Инициализируем GL3W
	if (gl3wInit()) {
		fprintf(stderr, "failed to initialize OpenGL\n");
		return;
	}
	if (!gl3wIsSupported(contextParams.major, contextParams.minor)) {
		fprintf(stderr, "OpenGL %i.%i not supported\n", contextParams.major, contextParams.minor);
		return;
	}
	printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));
	
	glEnable(GL_MULTISAMPLE);;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LESS);

	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
}

void st::Window::updateMaxResolution()
{
	resolution.x = 800;
	resolution.y = 600;

    #ifdef __linux__ 
		//TODO: for linux
		Display* d = XOpenDisplay(nullptr);
		Screen* s  = DefaultScreenOfDisplay(d);

		maxResolution.x = s->width;
		maxResolution.y = s->height;

	#elif _WIN32
		RECT desktop;
		// Get a handle to the desktop window
		const HWND hDesktop = GetDesktopWindow();
		// Get the size of screen to the variable desktop
		GetWindowRect(hDesktop, &desktop);
		// The top left corner will have coordinates (0,0)
		// and the bottom right corner will have coordinates
		// (horizontal, vertical)
		maxResolution.x = desktop.right;
		maxResolution.y = desktop.bottom;
	#else
		//TODO: maybe Mac or some shit
	#endif
}