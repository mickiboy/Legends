#include "impl/RendererImpl_GL.h"
#include "core/App.h"

namespace graphics {
    Renderer::Renderer(core::App& app) {
        impl = std::make_shared<RendererImpl_GL>(app);
    }

    Renderer::~Renderer() {
        impl.reset();
    }

    void Renderer::receiveEvent(const core::ResizeEvent& event) {
        if (impl) {
            impl->receiveEvent(event);
        }
    }

    void Renderer::setCamera(Camera* camera) {
        if (impl) {
            impl->setCamera(camera);
        }
    }

    void Renderer::clear() {
        if (impl) {
            impl->clear();
        }
    }

    void Renderer::draw(Sprite* sprite) {
        if (impl) {
            impl->draw(sprite);
        }
    }
}
