#if _WIN32

#include "AppImpl_win32.h"
#include "SurfaceImpl_win32.h"

namespace Legends {
    SurfaceImpl_win32::SurfaceImpl_win32(App& app, int width, int height)
            : SurfaceImpl(app, width, height) {
        AppImpl_win32* appImpl = reinterpret_cast<AppImpl_win32*>(app.getImpl());
        RECT windowRect = {0, 0, static_cast<LONG>(width), static_cast<LONG>(height)};
        AdjustWindowRectEx(&windowRect, WS_OVERLAPPEDWINDOW, FALSE, WS_EX_APPWINDOW);

        width = windowRect.right - windowRect.left;
        height = windowRect.bottom - windowRect.top;
        auto posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
        auto posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;

        window = CreateWindowEx(WS_EX_APPWINDOW, appImpl->className, L"Legends",
                                WS_OVERLAPPEDWINDOW, posX, posY, width, height,
                                nullptr, nullptr, GetModuleHandle(nullptr), nullptr);

        ShowWindow(window, SW_SHOW);
    }

    SurfaceImpl_win32::~SurfaceImpl_win32() {
        DestroyWindow(window);
    }

    RawSurface SurfaceImpl_win32::getRawSurface() {
        return window;
    }

    int SurfaceImpl_win32::getWidth() const {
        RECT rect;

        GetClientRect(window, &rect);

        return static_cast<int>(rect.right - rect.left);
    }

    int SurfaceImpl_win32::getHeight() const {
        RECT rect;

        GetClientRect(window, &rect);

        return static_cast<int>(rect.bottom - rect.top);
    }
}

#endif