#if __linux__

#include <Legends/EventManager.h>
#include "AppImpl_linux.h"

namespace Legends {
    Bool checkEvent(Display* display, XEvent* event, XPointer userData) {
        return event->xany.window == reinterpret_cast<Window>(userData);
    }
    
    AppImpl_linux::AppImpl_linux() {
        XInitThreads();
        
        display = XOpenDisplay(nullptr);
    }

    AppImpl_linux::~AppImpl_linux() {
        XCloseDisplay(display);
    }

    bool AppImpl_linux::isRunning() const {
        return running;
    }

    void AppImpl_linux::pollEvents() {
        XEvent event;
        
        while (XCheckIfEvent(display, &event, &checkEvent, reinterpret_cast<XPointer>(&window))) {
            switch (event.type) {
                case DestroyNotify:
                    running = false;
                    break;
                
                case ConfigureNotify:
                    EventManager::notify<ResizeEvent>(event.xconfigure.width,
                                                      event.xconfigure.height);
                    break;
            }
        }
    }
    
    Display* AppImpl_linux::getDisplay() {
        return display;
    }

    void AppImpl_linux::setWindow(Window* window) {
        this->window = window;
    }
}

#endif
