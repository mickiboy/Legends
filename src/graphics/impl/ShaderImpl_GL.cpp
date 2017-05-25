#include <fstream>
#include <glm/gtc/type_ptr.hpp>
#include "ShaderImpl_GL.h"
#include "TextureImpl_GL.h"

namespace graphics {
    ShaderImpl_GL::ShaderImpl_GL(const std::string& vertexShaderPath,
                                 const std::string& fragmentShaderPath)
        : Shader::Impl(vertexShaderPath, fragmentShaderPath) {
        std::string vertexShader;
        std::string fragmentShader;

        std::ifstream vertexShaderFile(vertexShaderPath, std::ios::in | std::ios::binary);
        if (vertexShaderFile) {
            vertexShaderFile.seekg(0, std::ios::end);
            vertexShader.resize(vertexShaderFile.tellg());
            vertexShaderFile.seekg(0, std::ios::beg);

            vertexShaderFile.read(&vertexShader[0], vertexShader.size());

            vertexShaderFile.close();
        }

        std::ifstream fragmentShaderFile(fragmentShaderPath, std::ios::in | std::ios::binary);
        if (fragmentShaderFile) {
            fragmentShaderFile.seekg(0, std::ios::end);
            fragmentShader.resize(fragmentShaderFile.tellg());
            fragmentShaderFile.seekg(0, std::ios::beg);

            fragmentShaderFile.read(&fragmentShader[0], fragmentShader.size());

            fragmentShaderFile.close();
        }

        auto vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
        auto vertexShaderStr = vertexShader.c_str();
        glShaderSource(vertexShaderId, 1, &vertexShaderStr, nullptr);
        glCompileShader(vertexShaderId);

        auto fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
        auto fragmentShaderStr = fragmentShader.c_str();
        glShaderSource(fragmentShaderId, 1, &fragmentShaderStr, nullptr);
        glCompileShader(fragmentShaderId);

        programId = glCreateProgram();
        glAttachShader(programId, vertexShaderId);
        glAttachShader(programId, fragmentShaderId);
        glLinkProgram(programId);

        glDeleteShader(fragmentShaderId);
        glDeleteShader(vertexShaderId);
    }

    ShaderImpl_GL::~ShaderImpl_GL() {
        glDeleteProgram(programId);
    }

    void ShaderImpl_GL::setMatrix(const std::string& name, const glm::mat4& matrix) {
        auto location = glGetUniformLocation(programId, name.c_str());

        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void ShaderImpl_GL::setTexture(Texture& texture) {
        auto textureImpl = reinterpret_cast<TextureImpl_GL*>(texture.getImpl());

        glBindTexture(GL_TEXTURE_2D, textureImpl->getTextureId());
    }

    GLuint ShaderImpl_GL::getProgramId() {
        return programId;
    }
}
