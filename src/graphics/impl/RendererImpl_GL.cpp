#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include "core/App.h"
#include "graphics/Camera.h"
#include "graphics/Sprite.h"
#include "MeshImpl_GL.h"
#include "RendererImpl_GL.h"
#include "ShaderImpl_GL.h"

namespace graphics {
    RendererImpl_GL::RendererImpl_GL(core::App& app)
        : Renderer::Impl(app) {
        int width;
        int height;

        app.getSize(&width, &height);

        glViewport(0, 0, width, height);
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    }

    RendererImpl_GL::~RendererImpl_GL() {
    }

    void RendererImpl_GL::receiveEvent(const core::ResizeEvent& event) {
        glViewport(0, 0, event.width, event.height);

        if (camera) {
            camera->setViewport(event.width, event.height);
        }
    }

    void RendererImpl_GL::setCamera(Camera* camera) {
        this->camera = camera;
    }

    void RendererImpl_GL::clear() {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void RendererImpl_GL::draw(Sprite* sprite) {
        auto meshImpl = reinterpret_cast<MeshImpl_GL*>(sprite->getMesh()->getImpl());
        auto shaderImpl = reinterpret_cast<ShaderImpl_GL*>(sprite->getShader()->getImpl());

        glUseProgram(shaderImpl->getProgramId());

        auto modelMatrix = glGetUniformLocation(shaderImpl->getProgramId(), "model");
        auto viewMatrix = glGetUniformLocation(shaderImpl->getProgramId(), "view");
        auto projectionMatrix = glGetUniformLocation(shaderImpl->getProgramId(), "projection");

        glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, glm::value_ptr(glm::mat4()));
        glUniformMatrix4fv(viewMatrix, 1, GL_FALSE, glm::value_ptr(camera->getViewMatrix()));
        glUniformMatrix4fv(projectionMatrix, 1, GL_FALSE, glm::value_ptr(camera->getProjectionMatrix()));

        sprite->getShader()->setTexture(*sprite->getTexture());

        glBindVertexArray(meshImpl->getVAO());
        glDrawElements(GL_TRIANGLES, meshImpl->getIndexSize(), GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);
    }
}
