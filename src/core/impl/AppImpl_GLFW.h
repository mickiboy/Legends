#pragma once

#include <GLFW/glfw3.h>
#include "core/App.h"

namespace core {
    class AppImpl_GLFW : public App::Impl {
    public:
        AppImpl_GLFW(const std::string& name, int width, int height);
        virtual ~AppImpl_GLFW();

        void getSize(int* width, int* height) override;

        bool isRunning() override;

        void pollEvents() override;
        void swapBuffers() override;

    private:
        GLFWwindow* window = nullptr;

        static void onFramebufferSizeChange(GLFWwindow* window,
                                            int width,
                                            int height);
    };
}
