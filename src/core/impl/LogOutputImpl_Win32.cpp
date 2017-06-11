#ifdef _WIN32

#include <iostream>
#include "LogOutputImpl_Win32.h"

namespace core {
    LogOutputImpl_Win32::LogOutputImpl_Win32() {
        console = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    LogOutputImpl_Win32::~LogOutputImpl_Win32() {
        console = nullptr;
    }

    void LogOutputImpl_Win32::writeToConsole(Log::Type type, const std::string& line) {
        switch (type) {
        case Log::Debug:
            SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
            break;

        case Log::Warning:
            SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED);
            break;

        case Log::Error:
            SetConsoleTextAttribute(console, FOREGROUND_RED);
            break;
        }

        std::cout << line;
        OutputDebugStringA(line.c_str());

        SetConsoleTextAttribute(console, 0);
    }
}

#endif
