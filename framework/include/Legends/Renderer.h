#pragma once

#include "EventManager.h"
#include "Surface.h"

namespace Legends {
    /**
     * A renderer is responsible for getting raw graphics data and dispatching
     * it to the GPU.
     *
     * <i>Receives ResizeEvent.</i>
     */
    class Renderer : public Receiver<ResizeEvent> {
    public:
        /**
         * Creates an instance of a renderer for a Surface.
         *
         * @param surface Instance of Surface
         */
        Renderer(Surface& surface);

        /**
         * Creates an instance of a renderer for a RawSurface, useful for
         * GUI frameworks like QT or wxWidgets.
         *
         * @param surface The raw surface
         * @param width The width of the raw surface
         * @param height The height of the raw surface
         */
        Renderer(RawSurface surface, int width, int height);
        
        /**
         * Creates an instance of a renderer for a RawDisplay and a RawSurface,
         * useful for GUI frameworks like QT or wxWidgets.
         *
         * @param display The raw display
         * @param surface The raw surface
         * @param width The width of the raw surface
         * @param height The height of the raw surface
         */
        Renderer(RawDisplay display, RawSurface surface, int width, int height);
        
        ~Renderer();

        void receiveEvent(const ResizeEvent& event);

        /**
         * Initializes the back buffer.
         */
        void clear();

        /**
         * Swaps the back with the front buffer.
         */
        void present();

    private:
        void init(RawDisplay display, RawSurface surface, int width, int height);
    };
}
