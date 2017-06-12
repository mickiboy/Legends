#include "core/ResourceManager.h"

namespace core {
    std::map<std::string, std::shared_ptr<Resource>> ResourceManager::resources;

    void ResourceManager::dispose() {
        for (auto& resource : resources) {
            resource.second.reset();
        }
    }
}
