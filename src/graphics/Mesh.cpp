#include "impl/MeshImpl_GL.h"

namespace graphics {
    Mesh::Mesh(const std::vector<float>& vertices,
               const std::vector<uint32_t>& indices) {
        impl = std::make_shared<MeshImpl_GL>(vertices, indices);
    }

    Mesh::~Mesh() {
        impl.reset();
    }

    Mesh::Impl* Mesh::getImpl() {
        return impl ? impl.get() : nullptr;
    }
}
