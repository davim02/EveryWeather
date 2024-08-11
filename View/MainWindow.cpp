#include "MainWindow.h"
#include "SensorDialogs/EditSensorDialog.h"
#include <QHBoxLayout>
#include <QWidget>
#include <QMenu>

MainWindow::MainWindow(Repository* repository, QWidget *parent): QMainWindow(parent), has_unchanged_changes(false)
{
    QWidget* mainWidget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(this);

    sensors_list = new SensorsList(repository, this);
    layout->addWidget(sensors_list);

    sensor_graph_widget = new SensorGraphWidget(this);
    layout->addWidget(sensor_graph);

    connect(sensors_list, &SensorsList::sensorSelected, sensor_graph_widget, &SensorGraphWidget::setSensorInfo);

    mainWidget->setLayout(layout);
    mainWidget->setMinimumSize(700, 400);
    mainWidget->setBackgroundRole(QPalette::Light);
    
    setCentralWidget(mainWidget);

    setWindowTitle("EveryWeather");
    setMinimumSize(700, 400);
    setBackgroundRole(QPalette::Light);

    create_sensor = new QAction(
        //QIcon(QPixmap((":/assets/icons/new_sensor.svg"))),
        "New Sensor"
    );
    create_sensor->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));
    create_sensor->setEnabled(false);

    //Sets menu
    QMenu* sensor_menu = menuBar()->addMenu("&Sensor");
    sensor_menu->addAction(create_sensor);

    connect(create_sensor, &QAction::triggered, this, &MainWindow::createSensor);
}

void MainWindow::createSensor() {
    EditSensorDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Sensor sensor = dialog.getSensor();
        repository->addSensor(sensor);
        sensors_list->show(); // refresh sensors list
        has_unsaved_changes = true;
        
    }
}

void MainWindow::editSensor(const Sensor* sensor) {
    EditSensorDialog dialog(this, sensor);
    if (dialog.exec() == QDialog::Accepted) {
        Sensor new_sensor = dialog.getSensor();
        repository->updateSensor(sensor, new_sensor);
        sensors_list->show(); // refresh sensors list
        has_unsaved_changes = true;
    }
}
