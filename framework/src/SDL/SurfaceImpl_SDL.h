#pragma once

#define SDL_MAIN_AVAILABLE
#ifdef _MSC_VER
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <Legends/Surface.h>

namespace Legends {
    class App;

    class SurfaceImpl_SDL : public SurfaceImpl {
    public:
        SurfaceImpl_SDL(App& app, int width, int height);
        virtual ~SurfaceImpl_SDL();

        RawDisplay getRawDisplay() override;
        RawSurface getRawSurface() override;
        int getWidth() const override;
        int getHeight() const override;

    private:
        SDL_Window* window = nullptr;
    };
}
