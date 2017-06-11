#pragma once

#include "core/Log.h"

namespace core {
    class LogOutputImpl_ANSI : public LogOutputImpl {
    public:
        LogOutputImpl_ANSI() {}
        virtual ~LogOutputImpl_ANSI() {}

        void writeToConsole(LogLevel level, const std::string& line) override;
    };
}
