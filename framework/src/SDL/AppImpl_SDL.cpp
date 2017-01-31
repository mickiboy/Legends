#define SDL_MAIN_AVAILABLE
#ifdef _MSC_VER
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <Legends/EventManager.h>
#include "AppImpl_SDL.h"

namespace Legends {
    AppImpl_SDL::AppImpl_SDL() {
        SDL_SetMainReady();
        SDL_Init(SDL_INIT_VIDEO);
    }

    AppImpl_SDL::~AppImpl_SDL() {
        SDL_Quit();
    }

    bool AppImpl_SDL::isRunning() const {
        return running;
    }

    void AppImpl_SDL::pollEvents() {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_WINDOWEVENT: {
                    switch (event.window.event) {
                        case SDL_WINDOWEVENT_SIZE_CHANGED:
                            EventManager::notify<ResizeEvent>(event.window.data1,
                                                              event.window.data2);
                            break;
                    }

                    break;
                }
            }
        }
    }
}
