#pragma once

#include <memory>
#include <string>
#include "World.h"

namespace core {
    class Scene {
    public:
        Scene(const std::string& configPath);

        World& getWorld();

    private:
        World world;
    };

    class SceneManager {
    public:
        ~SceneManager() {}

        static void dispose();

        static Scene* getCurrentScene();

        static void loadScene(const std::string& configPath);

    private:
        SceneManager() {}

        static std::shared_ptr<Scene> currentScene;
    };
}
