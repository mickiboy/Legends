#ifdef _WIN32

#include <cstdlib>
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

int main(int argc, char* argv[]);

int __stdcall wWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       wchar_t* lpCmdLine,
                       int nCmdShow) {
    return main(__argc, __argv);
}

#endif