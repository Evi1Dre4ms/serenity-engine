cmake_minimum_required(VERSION 3.10)

# build and compiler parameters
set(CMAKE_GENERATOR "Ninja")
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin") #EXE output path

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Export compile_commands.json for VS Code

# set the project name
project(serenity-engine)

# recursively collect source files
file(GLOB_RECURSE SRC
    "src/*.hpp"
    "src/*.cpp"
	"src/*.h"
	"src/*.c"
	"src/*.cc",
	"build/depends/gl3w/src/*.c"
)

# add 3rdparty libraries
set(INCLUDE_DIRS
	"src"
	"include"
	"depends/fmt/include"
	"depends/glfw/include"
	"depends/glm"
	"depends/freetype2/include"
	"build/depends/gl3w/include"
)
include_directories(${INCLUDE_DIRS})

add_subdirectory("depends/gl3w")
add_subdirectory("depends/glfw")
add_subdirectory("depends/fmt")
add_subdirectory("depends/freetype2")

find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})

# add the executable
add_executable(serenity-engine ${SRC})

# set link libraries
target_link_libraries(${PROJECT_NAME} glfw fmt freetype OpenGL::GL)

# set executable name
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "SerenityEngine")