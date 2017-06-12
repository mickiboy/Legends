#pragma once

#include "core/TaskManager.h"

namespace core {
    class World;
}

namespace graphics {
    class Renderer;

    class SpriteRendererTask : public core::Task {
    public:
        SpriteRendererTask(Renderer& renderer);
        virtual ~SpriteRendererTask();

        void execute(core::World& world) override;

    private:
        Renderer& renderer;
    };
}
