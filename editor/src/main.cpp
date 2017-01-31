#include <QApplication>
#include "MainWindow.h"

int main(int argc, char* argv[]) {
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    MainWindow window;

    window.show();

    return app.exec();
}