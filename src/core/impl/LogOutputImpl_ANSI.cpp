#include <iostream>
#include "LogOutputImpl_ANSI.h"

#define ANSI_COLOR_RESET  "\x1b[0m"
#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"

namespace core {
    void LogOutputImpl_ANSI::writeToConsole(LogLevel level, const std::string& line) {
        switch (level) {
        case Warning:
            std::cout << ANSI_COLOR_YELLOW;
            break;

        case Error:
            std::cout << ANSI_COLOR_RED;
            break;
        }

        std::cout << line << ANSI_COLOR_RESET;
    }
}
