#pragma once

#include <chrono>
#include <memory>
#include <string>
#include <vector>

namespace core {
    class Log {
    public:
        enum Type {
            Debug,
            Warning,
            Error
        };

        ~Log() {}

        static void init();
        static void shutdown();

        static void debug(const std::string& msg, const std::string& category = "");
        static void warning(const std::string& msg, const std::string& category = "");
        static void error(const std::string& msg, const std::string& category = "");

        class OutputImpl {
        public:
            OutputImpl() {}
            virtual ~OutputImpl() {}

            virtual void writeToConsole(Type type, const std::string& line) = 0;
        };

    private:
        Log() {}

        static std::shared_ptr<OutputImpl> outputImpl;
        static std::chrono::high_resolution_clock::time_point begin;
        static std::vector<std::string> lines;

        static void write(Type type, const std::string& msg, const std::string& category);
    };
}
