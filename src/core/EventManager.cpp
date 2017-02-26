#include "EventManager.h"

namespace core {
    std::map<std::type_index, std::set<void*>> EventManager::receivers;
}