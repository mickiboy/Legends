#pragma once

#include <memory>
#include "core/EventManager.h"

namespace core {
    class App;
}

namespace graphics {
    class Camera;
    class Sprite;

    /**
     * A renderer is responsible for getting raw graphics data and dispatching
     * it to the GPU.
     *
     * <i>Receives ResizeEvent.</i>
     */
    class Renderer : public core::Receiver<core::ResizeEvent> {
    public:
        /**
         * Creates an instance of a renderer for an application.
         *
         * @param app Instance of App
         */
        Renderer(core::App& app);
        
        ~Renderer();

        void receiveEvent(const core::ResizeEvent& event);

        void setCamera(Camera* camera);

        /**
         * Initializes the back buffer.
         */
        void clear();

        void draw(Sprite* sprite);

        class Impl {
        public:
            Impl(core::App& app) {}
            virtual ~Impl() {}

            virtual void receiveEvent(const core::ResizeEvent& event) = 0;

            virtual void clear() = 0;
            virtual void setCamera(Camera* camera) = 0;
            virtual void draw(Sprite* sprite) = 0;
        };

    private:
        std::shared_ptr<Impl> impl;
    };
}
