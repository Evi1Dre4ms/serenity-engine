#pragma once
#include "Engine/ECS/Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

static constexpr auto ComponentCount = 512;
static constexpr auto SystemCount = 32;

//TODO: Create define for Components that indicates 
// to generate Flatbuffer packet for network library

struct Transform : public ecs::Component<Transform>
{
    Transform(glm::vec3 p = glm::vec3(0.0), 
			  glm::quat r = glm::quat(1.0, 0.0, 0.0, 0.0), 
			  glm::vec3 s = glm::vec3(1.0),
              glm::vec3 v = glm::vec3(0.0)) : position(p), rotation(r), scale(s), velocity(v)
    {

    }

    glm::vec3 position;
	glm::quat rotation;
	glm::vec3 scale;

    glm::vec3 velocity;
};

struct Input : public ecs::Component<Input>{

    Input() = default;

    // TODO: maybe I should use a bitset here
    bool W = false;
    bool A = false;
    bool S = false;
    bool D = false;
};

struct Camera : public ecs::Component<Camera>{

    Camera() = default;

    glm::vec3 pos   = glm::vec3(9.0f, 20.0f, 9.0f);
    glm::vec2 angle = glm::vec2(0.0f, 0.0f); // horizontal/vertical

    float FoV       = glm::radians(67.0f);
    float aspect    = 16.0f / 9.0f;
    float clip_near = 0.1f;
    float clip_far  = 2500.0f;

    glm::vec3 ray;

    //matrices
    glm::mat4 projectionMatrix, viewMatrix;
    glm::mat4 orthoMatrix;

    glm::vec3 direction, right, up;
};