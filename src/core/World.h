#pragma once

#include "graphics/Camera.h"
#include "graphics/Sprite.h"

const int MAX_ENTITY_NUMBER = 500;

namespace core {
    class World {
    private:
        graphics::Camera cameraComponents[MAX_ENTITY_NUMBER];
        graphics::Sprite spriteComponents[MAX_ENTITY_NUMBER];
    };
}
