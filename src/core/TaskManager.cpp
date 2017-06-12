#include "TaskManager.h"
#include "World.h"
#include "graphics/Renderer.h"
#include "graphics/SpriteRendererTask.h"

namespace core {
    std::shared_ptr<Task> TaskManager::tasks[1];

    void TaskManager::init(graphics::Renderer& renderer) {
        tasks[0] = std::make_shared<graphics::SpriteRendererTask>(renderer);
    }

    void TaskManager::dispose() {
        for (auto task : tasks) {
            task.reset();
        }
    }

    void TaskManager::run(World& world) {
        for (auto task : tasks) {
            task->execute(world);
        }
    }
}
