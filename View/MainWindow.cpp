#include "MainWindow.h"


#include <QWidget>

MainWindow::MainWindow(Repository* repository, QWidget *parent)
    : QMainWindow(parent)
{
    sensors_list = new SensorsList(repository);
    setCentralWidget(sensors_list);
    sensors_list->show();

    setWindowTitle("EveryWeather");
    setMinimumSize(700, 400);
    setBackgroundRole(QPalette::Light);
};

