#pragma once

#if _WIN32

#define UNICODE
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <Legends/Surface.h>

namespace Legends {
    class App;

    class SurfaceImpl_win32 : public SurfaceImpl {
    public:
        SurfaceImpl_win32(App& app, int width, int height);
        virtual ~SurfaceImpl_win32();

        RawSurface getRawSurface() override;
        int getWidth() const override;
        int getHeight() const override;

    private:
        HWND window = nullptr;
    };
}

#endif