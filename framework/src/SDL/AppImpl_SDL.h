#pragma once

#include <Legends/App.h>

namespace Legends {
    class AppImpl_SDL : public AppImpl {
    public:
        AppImpl_SDL();
        virtual ~AppImpl_SDL();

        bool isRunning() const override;

        void pollEvents() override;

    private:
        bool running = true;
    };
}
