#pragma once

#include <memory>
#include <string>
#include "core/ResourceManager.h"

namespace graphics {
    class Texture : public core::Resource {
    public:
        Texture(const std::string& path);
        ~Texture();

        int getWidth() const;
        int getHeight() const;

    private:
        friend class TextureImpl_GL;

        class Impl {
        public:
            Impl(const std::string& path) {}
            virtual ~Impl() {}

            virtual int getWidth() const = 0;
            virtual int getHeight() const = 0;
        };

        std::shared_ptr<Impl> impl;

    public:
        Impl* getImpl();
    };
}
