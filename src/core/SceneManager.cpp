#include <yaml-cpp/yaml.h>
#include "SceneManager.h"

namespace core {
    std::shared_ptr<Scene> SceneManager::currentScene;

    Scene::Scene(const std::string& configPath) {
        auto config = YAML::LoadFile("assets/scenes/dummy.yaml");

        for (auto& entity : config["entities"]) {
            auto name = entity["name"].as<std::string>();

            auto worldEntity = world.createEntity(name);

            if (entity["components"]["Camera"].IsDefined()) {
                auto camera = world.assignCamera(worldEntity);

                auto width = entity["components"]["Camera"]["width"].as<int>();
                auto height = entity["components"]["Camera"]["height"].as<int>();

                camera->setViewport(width, height);
            }

            if (entity["components"]["Sprite"].IsDefined()) {
                auto sprite = world.assignSprite(worldEntity);

                auto texture = entity["components"]["Sprite"]["texture"].as<std::string>();

                sprite->load(texture);
            }
        }
    }

    World& Scene::getWorld() {
        return world;
    }

    void SceneManager::dispose() {
        currentScene.reset();
    }

    Scene* SceneManager::getCurrentScene() {
        return currentScene.get();
    }

    void SceneManager::loadScene(const std::string& configPath) {
        currentScene = std::make_shared<Scene>(configPath);
    }
}
