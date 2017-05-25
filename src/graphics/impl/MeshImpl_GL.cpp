#include "MeshImpl_GL.h"

namespace graphics {
    MeshImpl_GL::MeshImpl_GL(const std::vector<float>& vertices,
                             const std::vector<uint32_t>& indices)
        : Mesh::Impl(vertices, indices) {
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(vao);
        {
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * indices.size(), indices.data(), GL_STATIC_DRAW);

            // Vertex coordinates
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, nullptr);
            glEnableVertexAttribArray(0);

            // Texture coordinates
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, reinterpret_cast<void*>(sizeof(float) * 3));
            glEnableVertexAttribArray(1);
        }
        glBindVertexArray(0);

        indexSize = indices.size();
    }

    MeshImpl_GL::~MeshImpl_GL() {
        glDeleteBuffers(1, &ebo);
        glDeleteBuffers(1, &vbo);
        glDeleteVertexArrays(1, &vao);
    }

    GLuint MeshImpl_GL::getVAO() {
        return vao;
    }

    size_t MeshImpl_GL::getIndexSize() {
        return indexSize;
    }
}
