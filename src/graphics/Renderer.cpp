#include <glad/glad.h>
#include "../core/App.h"
#include "Renderer.h"

namespace graphics {
    Renderer::Renderer(core::App& app) {
        int width;
        int height;

        app.getSize(&width, &height);

        glViewport(0, 0, width, height);
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    }

    Renderer::~Renderer() {
    }

    void Renderer::receiveEvent(const core::ResizeEvent& event) {
        glViewport(0, 0, event.width, event.height);
    }

    void Renderer::clear() {
        glClear(GL_COLOR_BUFFER_BIT);
    }
}
