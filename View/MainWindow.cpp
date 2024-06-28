#include "MainWindow.h"


#include <QWidget>

MainWindow::MainWindow(Repository* repository, QWidget *parent): QMainWindow(parent)
{
    mainWidget = new MainWidget(repository, this);
    setCentralWidget(mainWidget);


    setWindowTitle("EveryWeather");
    setMinimumSize(700, 400);
    setBackgroundRole(QPalette::Light);
};

