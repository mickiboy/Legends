#pragma once

#include <memory>
#include <string>
#include <glm/gtc/matrix_transform.hpp>
#include "core/ResourceManager.h"

namespace graphics {
    class Texture;

    class Shader : public core::Resource {
    public:
        Shader(const std::string& vertexShaderPath,
               const std::string& fragmentShaderPath);
        ~Shader();

        void setMatrix(const std::string& name, const glm::mat4& matrix);
        void setTexture(Texture& texture);

    private:
        friend class ShaderImpl_GL;

        class Impl {
        public:
            Impl(const std::string& vertexShaderPath,
                 const std::string& fragmentShaderPath) {}
            virtual ~Impl() {}

            virtual void setMatrix(const std::string& name, const glm::mat4& matrix) = 0;
            virtual void setTexture(Texture& texture) = 0;
        };

        std::shared_ptr<Impl> impl;

    public:
        Impl* getImpl();
    };
}
