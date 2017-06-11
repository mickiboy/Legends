#include <iostream>
#include "LogOutputImpl_ANSI.h"

#define ANSI_COLOR_RESET  "\x1b[0m"
#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"

namespace core {
    void LogOutputImpl_ANSI::writeToConsole(Log::Type type, const std::string& line) {
        switch (type) {
        case Log::Warning:
            std::cout << ANSI_COLOR_YELLOW;
            break;

        case Log::Error:
            std::cout << ANSI_COLOR_RED;
            break;
        }

        std::cout << line << ANSI_COLOR_RESET;
    }
}
