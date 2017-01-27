#include <Legends/EventManager.h>

namespace Legends {
    std::map<std::type_index, std::set<void*>> EventManager::receivers;
}