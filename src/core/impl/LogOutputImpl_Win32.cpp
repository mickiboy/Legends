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

    void LogOutputImpl_Win32::writeToConsole(LogLevel level, const std::string& line) {
        switch (level) {
        case Debug:
            SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
            break;

        case Warning:
            SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED);
            break;

        case Error:
            SetConsoleTextAttribute(console, FOREGROUND_RED);
            break;
        }

        std::cout << line;
        OutputDebugStringA(line.c_str());

        SetConsoleTextAttribute(console, 0);
    }
}

#endif
