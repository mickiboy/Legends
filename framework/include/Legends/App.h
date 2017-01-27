#pragma once

#include <memory>

namespace Legends {
    class AppImpl;

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
        App();
        ~App();

        /**
         * Returns the actual platform-dependent implementation of App.
         *
         * @return A pointer to the current inheriting AppImpl instance
         */
        AppImpl* getImpl();

        /**
         * Checks if the app is still running.
         *
         * @return The result
         */
        bool isRunning() const;

        /**
         * Checks for new events and dispatches them to the internal handler.
         *
         * <b>Must be called every frame.</b>
         */
        void pollEvents();

    private:
        static bool isAlreadyCreated;

        std::shared_ptr<AppImpl> impl;
    };

    /**
     * An abstract class for platform-dependent implementations of an app loop.
     */
    class AppImpl {
    public:
        AppImpl() {}
        virtual ~AppImpl() {}

        /**
         * @see App::isRunning()
         * @return
         */
        virtual bool isRunning() const = 0;

        /**
         * @see App::pollEvents()
         */
        virtual void pollEvents() = 0;
    };
}