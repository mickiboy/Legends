#include <yaml-cpp/yaml.h>
#include "core/App.h"
#include "core/Log.h"
#include "core/ResourceManager.h"
#include "core/SceneManager.h"
#include "graphics/Camera.h"
#include "graphics/Renderer.h"
#include "graphics/Sprite.h"
#include "config.h"

const int DEFAULT_WIDTH = 1280;
const int DEFAULT_HEIGHT = 720;

int main(int argc, char* argv[]) {
    int width = DEFAULT_WIDTH;
    int height = DEFAULT_HEIGHT;

    core::Log::init();

    core::Log::warning("Warning", "test");
    core::Log::debug("Debug", "test");
    core::Log::error("Error", "test");

    core::App app(PROJECT_NAME, width, height);
    graphics::Renderer renderer(app);

    core::SceneManager::loadScene("assets/scenes/dummy.yaml");

    graphics::Camera camera(width, height);
    renderer.setCamera(&camera);

    graphics::Sprite sprite("assets/textures/container.jpg");

    while (app.isRunning()) {
        app.pollEvents();

        renderer.clear();
        renderer.draw(sprite);
        app.swapBuffers();
    }

    core::Log::debug("Closing game", "general");

    core::SceneManager::flush();
    core::ResourceManager::flush();

    core::Log::shutdown();

    return 0;
}
