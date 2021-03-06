#pragma once

#define STB_IMAGE_IMPLEMENTATION

#include <SDL2/SDL.h>
#include <glad/glad.h>

#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <memory>

#include "../inc/Shaders.hpp"
#include "../inc/linmath.h"
#include "../inc/stb_image.h"

namespace CowRender {
class Quad {
};
}  // namespace CowRender