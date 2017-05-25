#pragma once

#include <glad/glad.h>
#include "graphics/Texture.h"

namespace graphics {
    class TextureImpl_GL : public Texture::Impl {
    public:
        TextureImpl_GL(const std::string& path);
        virtual ~TextureImpl_GL();

        int getWidth() const override;
        int getHeight() const override;

        GLuint getTextureId();

    private:
        int width = 0;
        int height = 0;

        GLuint textureId;
    };
}
