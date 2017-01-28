#pragma once

#if __linux__

#include <X11/Xlib.h>
#include <Legends/Surface.h>

namespace Legends {
    class App;

    class SurfaceImpl_linux : public SurfaceImpl {
    public:
        SurfaceImpl_linux(App& app, int width, int height);
        virtual ~SurfaceImpl_linux();
        
        RawDisplay getRawDisplay() override;
        RawSurface getRawSurface() override;
        int getWidth() const override;
        int getHeight() const override;
    
    private:
        Display* display = nullptr;
        Window window;
    };
}

#endif
