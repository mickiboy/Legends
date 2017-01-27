#include <QTimer>
#include "MainWindow.h"
#include "RendererWidget.h"

MainWindow::MainWindow() {
    ui.setupUi(this);

    //auto timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer->start(1000 / 60);

    setCentralWidget(new RendererWidget);
}

void MainWindow::on_action_Exit_triggered(bool checked) {
    QApplication::exit(0);
}