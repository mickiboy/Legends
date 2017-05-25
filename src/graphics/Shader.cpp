#include "impl/ShaderImpl_GL.h"

namespace graphics {
    Shader::Shader(const std::string& vertexShaderPath,
                   const std::string& fragmentShaderPath) {
        impl = std::make_shared<ShaderImpl_GL>(vertexShaderPath, fragmentShaderPath);
    }

    Shader::~Shader() {
        impl.reset();
    }

    void Shader::setMatrix(const std::string& name, const glm::mat4& matrix) {
        if (impl) {
            impl->setMatrix(name, matrix);
        }
    }

    void Shader::setTexture(Texture& texture) {
        if (impl) {
            impl->setTexture(texture);
        }
    }

    Shader::Impl* Shader::getImpl() {
        return impl ? impl.get() : nullptr;
    }
}
