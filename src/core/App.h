#pragma once

#include <GLFW/glfw3.h>

namespace core {
    /**
     * Provides the global app loop for the game, where different events are
     * sent to the EventManager.
     *
     * <i><b>Can only be created once.</b> If an instance of App already
     * exists, nothing happens.</i>
     */
    class App {
    public:
        /**
         * Creates an instance of App.
         */
        App(int width, int height);
        ~App();

        void getSize(int* width, int* height);

        /**
         * Checks if the app is still running.
         *
         * @return The result
         */
        bool isRunning();

        /**
         * Checks for new events and dispatches them to the internal handler.
         *
         * <b>Must be called every frame.</b>
         */
        void pollEvents();

        void swapBuffers();

    private:
        static bool isAlreadyCreated;

        GLFWwindow* window = nullptr;
    };
}
