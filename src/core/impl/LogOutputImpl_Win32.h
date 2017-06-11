#pragma once

#ifdef _WIN32

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "core/Log.h"

namespace core {
    class LogOutputImpl_Win32 : public Log::OutputImpl {
    public:
        LogOutputImpl_Win32();
        virtual ~LogOutputImpl_Win32();

        void writeToConsole(Log::Type type, const std::string& line) override;

    private:
        HANDLE console = nullptr;
    };
}

#endif
