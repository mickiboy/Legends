#pragma once

#include <map>
#include <memory>
#include <string>

namespace core {
    class Resource {
    };

    class ResourceManager {
    public:
        ~ResourceManager() {}

        template<typename T, typename... Args>
        static T* load(const std::string& key, Args... args) {
            if (resources[key] == nullptr) {
                resources[key].reset(new T(std::forward<Args>(args)...));
            }

            return reinterpret_cast<T*>(resources[key].get());
        }

        static void flush();

    private:
        static std::map<std::string, std::shared_ptr<Resource>> resources;
    };
}
