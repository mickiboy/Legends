#include <exception>
#include <iostream>
#include "core/App.h"
#include "core/ResourceManager.h"
#include "graphics/Camera.h"
#include "graphics/Renderer.h"
#include "graphics/Sprite.h"
#include "config.h"

int main(int argc, char* argv[]) {
    try {
        core::App app(PROJECT_NAME, 1280, 720);
        graphics::Renderer renderer(app);

        graphics::Camera camera(1280, 720);
        renderer.setCamera(&camera);

        graphics::Sprite sprite("assets/textures/container.jpg");

        while (app.isRunning()) {
            app.pollEvents();

            renderer.clear();
            renderer.draw(sprite);
            app.swapBuffers();
        }

        core::ResourceManager::flush();

        return 0;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
}
