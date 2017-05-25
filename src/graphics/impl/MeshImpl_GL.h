#pragma once

#include <glad/glad.h>
#include "../Mesh.h"

namespace graphics {
    class MeshImpl_GL : public Mesh::Impl {
    public:
        MeshImpl_GL(const std::vector<float>& vertices,
                    const std::vector<uint32_t>& indices);
        virtual ~MeshImpl_GL();

        GLuint getVAO();
        size_t getIndexSize();

    private:
        GLuint vao;
        GLuint vbo;
        GLuint ebo;

        size_t indexSize;
    };
}
