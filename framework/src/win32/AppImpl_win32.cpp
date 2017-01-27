#if _WIN32

#include "AppImpl_win32.h"
#include <Legends/EventManager.h>

namespace Legends {
    AppImpl_win32::AppImpl_win32() {
        auto hInstance = GetModuleHandle(nullptr);
        WNDCLASSEX windowClass;

        memset(&msg, 0, sizeof(MSG));
        memset(&windowClass, 0, sizeof(windowClass));

        windowClass.cbSize = sizeof(WNDCLASSEX);
        windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
        windowClass.lpfnWndProc = WndProc;
        windowClass.cbClsExtra = 0;
        windowClass.cbWndExtra = 0;
        windowClass.hInstance = hInstance;
        windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
        windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
        windowClass.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
        windowClass.lpszMenuName = nullptr;
        windowClass.lpszClassName = className;
        windowClass.hIconSm = windowClass.hIcon;

        RegisterClassEx(&windowClass);
    }

    AppImpl_win32::~AppImpl_win32() {
    }

    bool AppImpl_win32::isRunning() const {
        return msg.message != WM_QUIT;
    }

    void AppImpl_win32::pollEvents() {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    LRESULT __stdcall AppImpl_win32::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        switch (msg) {
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;

            case WM_SIZE:
                EventManager::notify<ResizeEvent>(static_cast<int>(LOWORD(lParam)), static_cast<int>(HIWORD(lParam)));
                return 0;
        }

        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
}

#endif