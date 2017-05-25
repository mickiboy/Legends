#include "core/ResourceManager.h"

namespace core {
    std::map<std::string, std::shared_ptr<Resource>> ResourceManager::resources;

    void ResourceManager::flush() {
        for (auto& resource : resources) {
            resource.second.reset();
        }
    }
}
