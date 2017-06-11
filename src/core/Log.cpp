#include <fstream>
#include <iomanip>
#include <sstream>
#include "Log.h"

#ifdef _WIN32
#include "impl/LogOutputImpl_Win32.h"
#else
#include "impl/LogOutputImpl_ANSI.h"
#endif

namespace core {
    std::shared_ptr<Log::OutputImpl> Log::outputImpl;
    std::chrono::high_resolution_clock::time_point Log::begin;
    std::vector<std::string> Log::lines;

    void Log::init() {
#ifdef _WIN32
        outputImpl = std::make_shared<LogOutputImpl_Win32>();
#else
        outputImpl = std::make_shared<LogOutputImpl_ANSI>();
#endif

        begin = std::chrono::high_resolution_clock::now();

        debug("Logging started", "core::Log");
    }

    void Log::shutdown() {
        std::ofstream file("log.txt", std::ios::out | std::ios::trunc);

        if (file.is_open()) {
            for (auto line : lines) {
                file.write(line.c_str(), line.size());
            }

            file.close();
        }
    }

    void Log::debug(const std::string& msg, const std::string& category) {
        write(Debug, msg, category);
    }

    void Log::warning(const std::string& msg, const std::string& category) {
        write(Warning, msg, category);
    }

    void Log::error(const std::string& msg, const std::string& category) {
        write(Error, msg, category);
    }

    void Log::write(Type type, const std::string& msg, const std::string& category) {
        using namespace std::chrono;

        auto now = high_resolution_clock::now();
        auto time = now - begin;
        auto hours = duration_cast<std::chrono::hours>(time).count();
        auto minutes = duration_cast<std::chrono::minutes>(time).count();
        auto seconds = duration_cast<std::chrono::seconds>(time).count();
        auto nanoseconds = time.count();

        std::stringstream line;
        line << std::setfill('0')
            <<                 hours       << ':'
            << std::setw(2) << minutes     << ':'
            << std::setw(2) << seconds     << '.'
            <<                 nanoseconds << ' '
            << '[' << category << "] "
            << msg << '\n';

        auto lineStr = line.str();

        outputImpl->writeToConsole(type, lineStr);
        lines.push_back(lineStr);
    }
}
