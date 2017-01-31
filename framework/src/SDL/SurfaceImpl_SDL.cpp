#ifdef _MSC_VER
#include <SDL_syswm.h>
#else
#include <SDL2/SDL_syswm.h>
#endif
#include "SurfaceImpl_SDL.h"

namespace Legends {
    SurfaceImpl_SDL::SurfaceImpl_SDL(App& app, int width, int height)
            : SurfaceImpl(app, width, height) {
        window = SDL_CreateWindow("Legends",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  width, height,
                                  SDL_WINDOW_RESIZABLE
                                  | SDL_WINDOW_OPENGL
                                  | SDL_WINDOW_ALLOW_HIGHDPI);
    }

    SurfaceImpl_SDL::~SurfaceImpl_SDL() {
        SDL_DestroyWindow(window);
    }

    RawDisplay SurfaceImpl_SDL::getRawDisplay() {
        SDL_SysWMinfo info;

        SDL_VERSION(&info.version);
        SDL_GetWindowWMInfo(window, &info);

        switch (info.subsystem) {
            case SDL_SYSWM_UNKNOWN:
            default:
                return nullptr;

#if __linux__
            case SDL_SYSWM_X11:
                return info.info.x11.display;
#endif
        }
    }

    RawSurface SurfaceImpl_SDL::getRawSurface() {
        SDL_SysWMinfo info;

        SDL_VERSION(&info.version);
        SDL_GetWindowWMInfo(window, &info);

        switch (info.subsystem) {
            case SDL_SYSWM_UNKNOWN:
            default:
                return nullptr;

#if _WIN32
            case SDL_SYSWM_WINDOWS:
                return info.info.win.window;
#endif

#if __linux__
            case SDL_SYSWM_X11:
                return (void*)(uintptr_t) info.info.x11.window;
#endif
        }
    }

    int SurfaceImpl_SDL::getWidth() const {
        int width, height;

        SDL_GetWindowSize(window, &width, &height);

        return width;
    }

    int SurfaceImpl_SDL::getHeight() const {
        int width, height;

        SDL_GetWindowSize(window, &width, &height);

        return height;
    }
}
