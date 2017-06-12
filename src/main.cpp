#include "core/App.h"
#include "core/Log.h"
#include "core/ResourceManager.h"
#include "core/SceneManager.h"
#include "core/TaskManager.h"
#include "graphics/Renderer.h"
#include "config.h"

const int DEFAULT_WIDTH = 1280;
const int DEFAULT_HEIGHT = 720;

int main(int argc, char* argv[]) {
    int width = DEFAULT_WIDTH;
    int height = DEFAULT_HEIGHT;

    core::App app(PROJECT_NAME, width, height);
    graphics::Renderer renderer(app);

    core::TaskManager::init(renderer);
    core::SceneManager::loadScene("assets/scenes/dummy.yaml");

    while (app.isRunning()) {
        app.pollEvents();

        renderer.clear();
        core::TaskManager::run(core::SceneManager::getCurrentScene()->getWorld());
        app.swapBuffers();
    }

    core::log << "Closing the game" << std::endl;

    core::TaskManager::dispose();
    core::SceneManager::dispose();
    core::ResourceManager::dispose();

    return 0;
}
