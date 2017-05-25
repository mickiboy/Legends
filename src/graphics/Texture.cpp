#include "impl/TextureImpl_GL.h"

namespace graphics {
    Texture::Texture(const std::string& path) {
        impl = std::make_shared<TextureImpl_GL>(path);
    }

    Texture::~Texture() {
        impl.reset();
    }

    int Texture::getWidth() const {
        return impl ? impl->getWidth() : 0;
    }

    int Texture::getHeight() const {
        return impl ? impl->getHeight() : 0;
    }

    Texture::Impl* Texture::getImpl() {
        return impl ? impl.get() : nullptr;
    }
}
