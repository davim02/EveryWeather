#include "MainWindow.h"


#include <QWidget>

MainWindow::MainWindow(Repository* repository, QWidget *parent)
    : QMainWindow(parent), repository(repository)
{
    sensors_list = new SensorsList(repository);
    setCentralWidget(sensors_list);

    setWindowTitle("EveryWeather");
    setMinimumSize(400, 400);

};

