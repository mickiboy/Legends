#pragma once

#include <bitset>
#include <map>
#include <stack>
#include "graphics/Camera.h"
#include "graphics/Sprite.h"

const int MAX_ENTITY_NUMBER = 500;

namespace core {
    class World {
    public:
        World();

        int createEntity(std::string name = "");
        void destroyEntity(int id);

        int getEntityIdByName(const std::string& name);

        bool matchesPattern(int id, std::bitset<2> pattern);
        
        graphics::Camera* assignCamera(int id);
        graphics::Camera* getCamera(int id);
        void unassignCamera(int id);

        graphics::Sprite* assignSprite(int id);
        graphics::Sprite* getSprite(int id);
        void unassignSprite(int id);

    private:
        std::bitset<2> entities[MAX_ENTITY_NUMBER];
        std::stack<int> freeEntities;
        std::map<std::string, int> entityIdMap;

        graphics::Camera cameras[MAX_ENTITY_NUMBER];
        graphics::Sprite sprites[MAX_ENTITY_NUMBER];
    };
}
