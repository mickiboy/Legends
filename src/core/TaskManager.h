#pragma once

#include <memory>

namespace graphics {
    class Renderer;
}

namespace core {
    class World;

    class Task {
    public:
        virtual ~Task() {}

        virtual void execute(World& world) = 0;
    };

    class TaskManager {
    public:
        ~TaskManager() {}

        static void init(graphics::Renderer& renderer);
        static void dispose();

        static void run(World& world);

    private:
        TaskManager() {}

        static std::shared_ptr<Task> tasks[1];
    };
}
