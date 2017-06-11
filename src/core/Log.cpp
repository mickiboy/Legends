#include <fstream>
#include <iomanip>
#include "Log.h"

#ifdef _WIN32
#include "impl/LogOutputImpl_Win32.h"
#else
#include "impl/LogOutputImpl_ANSI.h"
#endif

namespace core {
    LogStream log;

    LogStream::LogStream() {
        start = std::chrono::high_resolution_clock::now();

#ifdef _WIN32
        outputImpl = std::make_shared<LogOutputImpl_Win32>();
#else
        outputImpl = std::make_shared<LogOutputImpl_ANSI>();
#endif

        *this << "Logging started" << std::endl;
    }

    LogStream::~LogStream() {
        save();
    }

    void LogStream::makeLine() {
        using namespace std::chrono;

        auto now = high_resolution_clock::now();
        auto time = now - start;
        auto hours = duration_cast<std::chrono::hours>(time).count();
        auto minutes = duration_cast<std::chrono::minutes>(time).count();
        auto seconds = duration_cast<std::chrono::seconds>(time).count();
        auto nanoseconds = time.count();
        auto msg = str();

        std::stringstream line;
        line << std::setfill('0') << hours << ':'
            << std::setw(2) << minutes << ':'
            << std::setw(2) << seconds << '.'
            << nanoseconds << ' '
            << msg << '\n';

        auto lineStr = line.str();

        outputImpl->writeToConsole(currentLevel, lineStr);
        lines.push_back(lineStr);

        str("");
    }

    void LogStream::save() {
        std::ofstream file("log.txt", std::ios::out | std::ios::trunc);

        if (file.is_open()) {
            for (auto line : lines) {
                file.write(line.c_str(), line.size());
            }

            file.close();
        }
    }
}
