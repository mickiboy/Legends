#include <stdexcept>
#include <glad/glad.h>
#include "EventManager.h"
#include "impl/AppImpl_GLFW.h"

namespace core {
    bool App::isAlreadyCreated = false;

    App::App(const std::string& name, int width, int height) {
        if (!isAlreadyCreated) {
            impl = std::make_shared<AppImpl_GLFW>(name, width, height);

            isAlreadyCreated = true;
        }
    }

    App::~App() {
        impl.reset();
    }

    void App::getSize(int* width, int* height) {
        if (impl) {
            impl->getSize(width, height);
        }
    }

    bool App::isRunning() {
        return impl ? impl->isRunning() : false;
    }

    void App::pollEvents() {
        if (impl) {
            impl->pollEvents();
        }
    }

    void App::swapBuffers() {
        if (impl) {
            impl->swapBuffers();
        }
    }
}
