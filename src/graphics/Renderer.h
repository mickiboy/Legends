#pragma once

#include "../core/EventManager.h"

namespace core {
    class App;
}

namespace graphics {
    /**
     * A renderer is responsible for getting raw graphics data and dispatching
     * it to the GPU.
     *
     * <i>Receives ResizeEvent.</i>
     */
    class Renderer : public core::Receiver<core::ResizeEvent> {
    public:
        Renderer();

        /**
         * Creates an instance of a renderer for an application.
         *
         * @param app Instance of App
         */
        Renderer(core::App& app);
        
        ~Renderer();

        void receiveEvent(const core::ResizeEvent& event);

        /**
         * Initializes the back buffer.
         */
        void clear();
    };
}
