#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>

namespace st
{

    struct VertexData
    {
        std::vector<unsigned int> indices;

        std::vector<glm::vec3> positions;
        std::vector<glm::vec3> normals;
        std::vector<glm::vec3> tangents;
        std::vector<glm::vec3> bitangents;

        std::vector<glm::vec2> texCoords;
        std::vector<glm::vec4> colors;
    };

    class ModelManager
    {

        private:


        public:



    };

}