#if _WIN32

#include <cstdlib>
#include <vector>
#define UNICODE
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <shellapi.h>

int main(int argc, char* argv[]);

int __stdcall wWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       wchar_t* lpCmdLine,
                       int nCmdShow) {
    /*int argc;
    std::vector<char*> argvVector;

    wchar_t** argvW = CommandLineToArgvW(lpCmdLine, &argc);

    for (auto i = 0; i < argc; i++) {
        char* arg = new char[lstrlenW(argvW[i])];
        wcstombs(arg, argvW[i], 512);
        argvVector.push_back(arg);
    }

    HeapFree(GetProcessHeap(), 0, argvW);

    auto result = main(argc, argvVector.data());

    return result;*/
    return main(__argc, __argv);
}

#endif