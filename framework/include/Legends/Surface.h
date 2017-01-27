#pragma once

#include <memory>

namespace Legends {
    using RawSurface = void*;

    class App;
    class SurfaceImpl;

    /**
     * Provides a drawing surface for a renderer.
     */
    class Surface {
    public:
        /**
         * Creates an instance of a Surface.
         *
         * @param app Instance of App
         * @param width Initial width of the Surface
         * @param height Initial height of the Surface
         */
        Surface(App& app, int width, int height);
        ~Surface();

        /**
         * Returns a pointer to the raw surface data.
         *
         * @return The raw surface
         */
        RawSurface getRawSurface();

        /**
         * Returns the current width of the Surface.
         *
         * @return Current width
         */
        int getWidth() const;

        /**
         * Returns the current height of the Surface.
         *
         * @return Current height
         */
        int getHeight() const;

    private:
        std::shared_ptr<SurfaceImpl> impl;
    };

    class SurfaceImpl {
    public:
        SurfaceImpl(App& app, int width, int height) {}
        virtual ~SurfaceImpl() {}

        virtual RawSurface getRawSurface() = 0;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
    };
}