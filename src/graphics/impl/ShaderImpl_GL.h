#pragma once

#include <glad/glad.h>
#include "../Shader.h"

namespace graphics {
    class ShaderImpl_GL : public Shader::Impl {
    public:
        ShaderImpl_GL(const std::string& vertexShaderPath,
                      const std::string& fragmentShaderPath);
        virtual ~ShaderImpl_GL();

        void setMatrix(const std::string& name, const glm::mat4& matrix) override;
        void setTexture(Texture& texture) override;

        GLuint getProgramId();

    private:
        GLuint programId;
    };
}
