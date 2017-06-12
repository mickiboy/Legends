#include "core/Log.h"
#include "core/World.h"
#include "Renderer.h"
#include "Sprite.h"
#include "SpriteRendererTask.h"

namespace graphics {
    const int TASK_PATTERN = 1 << 1;

    SpriteRendererTask::SpriteRendererTask(Renderer& renderer)
        : renderer(renderer) {
        core::log << "Initialized sprite renderer task" << std::endl;
    }

    SpriteRendererTask::~SpriteRendererTask() {
        core::log << "Shut down sprite renderer task" << std::endl;
    }

    void SpriteRendererTask::execute(core::World& world) {
        for (auto i = 0; i < MAX_ENTITY_NUMBER; i++) {
            if (world.matchesPattern(i, std::bitset<2>(TASK_PATTERN))) {
                auto mainCamera = world.getEntityIdByName("camera_main");

                auto camera = world.getCamera(mainCamera);
                auto sprite = world.getSprite(i);

                renderer.setCamera(camera);
                renderer.draw(sprite);
            }
        }
    }
}
