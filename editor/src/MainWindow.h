#include <QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

private slots:
    void on_action_Exit_triggered(bool checked = false);

private:
    Ui::MainWindow ui;
};