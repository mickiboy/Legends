#pragma once

#if _WIN32

#define UNICODE
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <Legends/App.h>

namespace Legends {
    class AppImpl_win32 : public AppImpl {
    public:
        AppImpl_win32();
        virtual ~AppImpl_win32();

        bool isRunning() const override;

        void pollEvents() override;

        const wchar_t* className = L"LEGENDS";

    private:
        MSG msg = {};

        static LRESULT __stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    };
}

#endif