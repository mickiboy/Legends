#include <sstream>
#include <glad/glad.h>
#include "AppImpl_GLFW.h"
#include "core/EventManager.h"
#include "core/Log.h"

namespace core {
    AppImpl_GLFW::AppImpl_GLFW(const std::string& name, int width, int height)
        : App::Impl(name, width, height) {
        if (!glfwInit()) {
            Log::error("Error while initializing GLFW", "core::AppImpl_GLFW");
            return;
        }

        Log::debug("Initialized GLFW", "core::AppImpl_GLFW");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width,
                                  height,
                                  name.c_str(),
                                  nullptr,
                                  nullptr);
        if (!window) {
            glfwTerminate();
            Log::error("Error while creating a window", "core::AppImpl_GLFW");
            return;
        }

        std::stringstream ss;
        ss << "Created a " << width << "x" << height << " window";
        Log::debug(ss.str(), "core::AppImpl_GLFW");

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
            glfwTerminate();
            Log::error("Error while loading GL extensions", "core::AppImpl_GLFW");
            return;
        }

        Log::debug("Loaded GL extensions", "core::AppImpl_GLFW");

        glfwSetFramebufferSizeCallback(window, onFramebufferSizeChange);
    }

    AppImpl_GLFW::~AppImpl_GLFW() {
        glfwTerminate();
    }

    void AppImpl_GLFW::getSize(int* width, int* height) {
        glfwGetFramebufferSize(window, width, height);
    }

    bool AppImpl_GLFW::isRunning() {
        return !glfwWindowShouldClose(window);
    }

    void AppImpl_GLFW::pollEvents() {
        glfwPollEvents();
    }

    void AppImpl_GLFW::swapBuffers() {
        glfwSwapBuffers(window);
    }

    void AppImpl_GLFW::onFramebufferSizeChange(GLFWwindow* window,
                                      int width,
                                      int height) {
        EventManager::notify<ResizeEvent>(width, height);
    }
}
