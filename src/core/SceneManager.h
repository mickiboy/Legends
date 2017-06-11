#pragma once

#include <memory>
#include <string>
#include "World.h"

namespace core {
    class Scene {
    public:
        Scene(const std::string& configPath);

    private:
        World world;
    };

    class SceneManager {
    public:
        static void flush();

        static void loadScene(const std::string& configPath);

    private:
        static std::shared_ptr<Scene> currentScene;
    };
}
