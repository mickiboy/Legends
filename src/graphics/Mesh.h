#pragma once

#include <cstdint>
#include <memory>
#include <vector>
#include "core/ResourceManager.h"

namespace graphics {
    class Mesh : public core::Resource {
    public:
        Mesh(const std::vector<float>& vertices,
             const std::vector<uint32_t>& indices);
        ~Mesh();

        class Impl {
        public:
            Impl(const std::vector<float>& vertices,
                 const std::vector<uint32_t>& indices) {}
            virtual ~Impl() {}
        };

        Impl* getImpl();

    private:
        std::shared_ptr<Impl> impl;
    };
}
