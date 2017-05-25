#include "TextureImpl_GL.h"
#define STB_IMAGE_IMPLEMENTATION
#include "graphics/stb_image.h"

namespace graphics {
    TextureImpl_GL::TextureImpl_GL(const std::string& path)
        : Texture::Impl(path) {
        int channels;
        auto data = stbi_load(path.c_str(), &width, &height, &channels, 4);

        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    TextureImpl_GL::~TextureImpl_GL() {
        glDeleteTextures(1, &textureId);
    }

    int TextureImpl_GL::getWidth() const {
        return width;
    }

    int TextureImpl_GL::getHeight() const {
        return height;
    }

    GLuint TextureImpl_GL::getTextureId() {
        return textureId;
    }
}
