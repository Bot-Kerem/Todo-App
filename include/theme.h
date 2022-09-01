#pragma once
#include <glm/vec3.hpp>

typedef glm::vec3 Color;

struct Theme{
    Color Background;
};


Theme getDefaultTheme();