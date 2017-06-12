#include "Log.h"
#include "World.h"

namespace core {
    World::World() {
        for (auto i = MAX_ENTITY_NUMBER; i > -1; i--) {
            freeEntities.push(i);
        }
    }

    int World::createEntity(std::string name) {
        if (freeEntities.empty()) {
            log << Error << "No free entities available" << std::endl;
            return -1;
        }

        auto id = freeEntities.top();
        freeEntities.pop();

        if (!name.empty()) {
            entityIdMap[name] = id;
        }

        return id;
    }

    void World::destroyEntity(int id) {
        entities[id].reset();
        freeEntities.push(id);
    }

    int World::getEntityIdByName(const std::string& name) {
        return entityIdMap[name];
    }

    bool World::matchesPattern(int id, std::bitset<2> pattern) {
        return (entities[id] & pattern) == pattern;
    }

    graphics::Camera* World::assignCamera(int id) {
        entities[id].set(0);
        return &cameras[id];
    }

    graphics::Camera* World::getCamera(int id) {
        if (entities[id].test(0)) {
            return &cameras[id];
        } else {
            return nullptr;
        }
    }

    void World::unassignCamera(int id) {
        entities[id].set(0, false);
    }

    graphics::Sprite* World::assignSprite(int id) {
        entities[id].set(1);
        return &sprites[id];
    }

    graphics::Sprite* World::getSprite(int id) {
        if (entities[id].test(1)) {
            return &sprites[id];
        } else {
            return nullptr;
        }
    }

    void World::unassignSprite(int id) {
        entities[id].set(1, false);
    }
}
