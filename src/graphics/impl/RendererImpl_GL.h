#pragma once

#include "../Renderer.h"

namespace graphics {
    class RendererImpl_GL : public Renderer::Impl {
    public:
        RendererImpl_GL(core::App& app);
        virtual ~RendererImpl_GL();

        void receiveEvent(const core::ResizeEvent& event) override;

        void setCamera(Camera* camera) override;

        void clear() override;
        void draw(Sprite& sprite) override;

    private:
        Camera* camera = nullptr;
    };
}
