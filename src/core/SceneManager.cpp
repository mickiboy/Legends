#include <yaml-cpp/yaml.h>
#include "SceneManager.h"

namespace core {
    std::shared_ptr<Scene> SceneManager::currentScene;

    Scene::Scene(const std::string& configPath) {
        auto config = YAML::LoadFile("assets/scenes/dummy.yaml");
    }

    void SceneManager::flush() {
        currentScene.reset();
    }

    void SceneManager::loadScene(const std::string& configPath) {
        currentScene = std::make_shared<Scene>(configPath);
    }
}
