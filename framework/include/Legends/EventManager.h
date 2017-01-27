#pragma once

#include <functional>
#include <map>
#include <set>
#include <typeindex>

namespace Legends {
    struct ResizeEvent {
        int width;
        int height;

        ResizeEvent(int width, int height) : width(width), height(height) {}
    };

    template<typename EventType, bool autoRegister = true>
    class Receiver;

    class EventManager {
    public:
        ~EventManager() {}

        template<typename EventType>
        static void registerReceiver(Receiver<EventType>* receiver) {
            receivers[typeid(EventType)].insert((void *&&) receiver);
        }

        template<typename EventType>
        static void unregisterReceiver(Receiver<EventType>* receiver) {
            receivers[typeid(EventType)].erase((void *&&) receiver);
        }

        template<typename EventType, typename... Args>
        static void notify(Args... args) {
            EventType event = EventType(std::forward<Args>(args)...);

            for (auto receiver : receivers[typeid(EventType)]) {
                reinterpret_cast<Receiver<EventType>*>(receiver)->receiveEvent(event);
            }
        };

    private:
        EventManager() {}

        static std::map<std::type_index, std::set<void*>> receivers;
    };

    template<typename EventType, bool autoRegister>
    class Receiver {
    public:
        Receiver() {
            if (autoRegister) EventManager::registerReceiver<EventType>(this);
        }

        virtual ~Receiver() {
            if (autoRegister) EventManager::unregisterReceiver<EventType>(this);
        }

        virtual void receiveEvent(const EventType& event) = 0;
    };
}