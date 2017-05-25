#pragma once

#include <memory>
#include <string>

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
        App(const std::string& name, int width, int height);
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

        class Impl {
        public:
            Impl(const std::string& name, int width, int height) {}
            virtual ~Impl() {}

            virtual void getSize(int* width, int* height) = 0;

            virtual bool isRunning() = 0;

            virtual void pollEvents() = 0;
            virtual void swapBuffers() = 0;
        };

    private:
        static bool isAlreadyCreated;

        std::shared_ptr<Impl> impl;
    };
}
