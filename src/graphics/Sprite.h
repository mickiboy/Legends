#pragma once

#include <string>

namespace graphics {
    class Mesh;
    class Shader;
    class Texture;

    class Sprite {
    public:
        Sprite(const std::string& path);

        Mesh* getMesh();
        Shader* getShader();
        Texture* getTexture();

    private:
        Shader* shader = nullptr;
        Texture* texture = nullptr;
        Mesh* mesh = nullptr;
    };
}
