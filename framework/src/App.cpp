#include <Legends/App.h>
#include "win32/AppImpl_win32.h"
#include "linux/AppImpl_linux.h"

namespace Legends {
    bool App::isAlreadyCreated = false;

    App::App() {
        if (!isAlreadyCreated) {
#if _WIN32
            impl = std::make_shared<AppImpl_win32>();
#elif __linux__
            impl = std::make_shared<AppImpl_linux>();
#endif

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
