#pragma once

#include "core/Log.h"

namespace core {
    class LogOutputImpl_ANSI : public Log::OutputImpl {
    public:
        LogOutputImpl_ANSI() {}
        virtual ~LogOutputImpl_ANSI() {}

        void writeToConsole(Log::Type type, const std::string& line) override;
    };
}
