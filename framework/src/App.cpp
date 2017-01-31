#include <Legends/App.h>
#include "SDL/AppImpl_SDL.h"

namespace Legends {
    bool App::isAlreadyCreated = false;

    App::App() {
        if (!isAlreadyCreated) {
            impl = std::make_shared<AppImpl_SDL>();
            isAlreadyCreated = true;
        }
    }

    App::~App() {
        impl.reset();
    }

    AppImpl* App::getImpl() {
        return impl.get();
    }

    bool App::isRunning() const {
        return impl->isRunning();
    }

    void App::pollEvents() {
        impl->pollEvents();
    }
}
