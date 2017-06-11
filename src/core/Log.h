#pragma once

#include <chrono>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

namespace core {
    enum LogLevel {
        Debug,
        Warning,
        Error
    };

    class LogOutputImpl {
    public:
        virtual ~LogOutputImpl() {}

        virtual void writeToConsole(LogLevel level, const std::string& line) = 0;
    };

    class LogStream : public std::ostringstream {
    public:
        LogStream();
        virtual ~LogStream();

        void makeLine();

        template<typename T> inline LogStream& operator<<(const T& t) {
            (*(std::ostringstream*) this) << t;
            return *this;
        }

        inline LogStream& operator<<(const LogLevel& level) {
            currentLevel = level;
            return *this;
        }

        typedef LogStream& (*LogStreamManipulator)(LogStream&);
        LogStream& operator<<(LogStreamManipulator manipulator) {
            return manipulator(*this);
        }

    private:
        std::shared_ptr<LogOutputImpl> outputImpl;
        std::chrono::high_resolution_clock::time_point start;
        std::vector<std::string> lines;

        LogLevel currentLevel = Debug;

        void save();
    };

    extern LogStream log;
}

namespace std {
    inline core::LogStream& endl(core::LogStream& out) {
        out.makeLine();
        out << core::Debug;
        return out;
    }
}
