#pragma once

#if __linux__

#include <X11/Xlib.h>
#include <Legends/App.h>

namespace Legends {
    class AppImpl_linux : public AppImpl {
    public:
        AppImpl_linux();
        virtual ~AppImpl_linux();

        bool isRunning() const override;

        void pollEvents() override;
        
        Display* getDisplay();
        
        void setWindow(Window* window);

    private:
        bool running = true;
        Display* display = nullptr;
        Window* window = nullptr;
    };
}

#endif
