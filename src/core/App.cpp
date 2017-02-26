#include <stdexcept>
#include <glad/glad.h>
#include "App.h"

namespace core {
    bool App::isAlreadyCreated = false;

    App::App(int width, int height) {
        if (!isAlreadyCreated) {
            if (!glfwInit()) {
                throw std::runtime_error("Error while initializing GLFW.");
            }

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

            window = glfwCreateWindow(width,
                                      height,
                                      "Legends",
                                      nullptr,
                                      nullptr);
            if (!window) {
                glfwTerminate();
                throw std::runtime_error("Error while creating a window.");
            }

            glfwMakeContextCurrent(window);

            if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
                glfwTerminate();
                throw std::runtime_error("Error while loading GL extensions.");
            }

            isAlreadyCreated = true;
        }
    }

    App::~App() {
        glfwTerminate();
    }

    void App::getSize(int* width, int* height) {
        glfwGetFramebufferSize(window, width, height);
    }

    bool App::isRunning() {
        return !glfwWindowShouldClose(window);
    }

    void App::pollEvents() {
        glfwPollEvents();
    }

    void App::swapBuffers() {
        glfwSwapBuffers(window);
    }
}
