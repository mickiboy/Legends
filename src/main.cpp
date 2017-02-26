#include <exception>
#include <iostream>
#include "core/App.h"
#include "graphics/Renderer.h"

int main(int argc, char* argv[]) {
    try {
        core::App app(1280, 720);
        graphics::Renderer renderer(app);

        while (app.isRunning()) {
            app.pollEvents();

            renderer.clear();
            app.swapBuffers();
        }

        return 0;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
}
