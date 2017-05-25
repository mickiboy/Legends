#include <sstream>
#include <vector>
#include "core/ResourceManager.h"
#include "graphics/Mesh.h"
#include "graphics/Shader.h"
#include "graphics/Sprite.h"
#include "graphics/Texture.h"

namespace graphics {
    Sprite::Sprite(const std::string& path) {
        shader = core::ResourceManager::load<graphics::Shader>("shader_default", "assets/shaders/GL/default.vert", "assets/shaders/GL/default.frag");

        std::stringstream textureKey;
        textureKey << "texture_" << path;
        texture = core::ResourceManager::load<graphics::Texture>(textureKey.str(), path);
        auto width = static_cast<float>(texture->getWidth());
        auto height = static_cast<float>(texture->getHeight());

        std::vector<float> vertices = {
            width, 0.0f, 0.0f, 1.0f, 0.0f,
            width, height, 0.0f, 1.0f, 1.0f,
            0.0f, height, 0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 0.0f
        };

        std::vector<uint32_t> indices = {
            0, 1, 3,
            1, 2, 3
        };

        std::stringstream meshKey;
        meshKey << "mesh_" << static_cast<int>(width) << "x" << static_cast<int>(height);
        mesh = core::ResourceManager::load<graphics::Mesh>(meshKey.str(), vertices, indices);
    }

    Mesh* Sprite::getMesh() {
        return mesh;
    }

    Shader* Sprite::getShader() {
        return shader;
    }

    Texture* Sprite::getTexture() {
        return texture;
    }
}
