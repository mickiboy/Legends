#include <Legends/App.h>
#include <Legends/Renderer.h>

int main(int argc, char* argv[]) {
    Legends::App app;
    Legends::Surface surface(app, 1280, 720);
    Legends::Renderer renderer(surface);

    while (app.isRunning()) {
        app.pollEvents();

        renderer.clear();
        renderer.present();
    }

    return 0;
}