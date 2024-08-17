#include "MainWindow.h"
#include "SensorDialogs/SensorEditorDialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QMessageBox>

MainWindow::MainWindow(Repository* repository, QWidget *parent): QMainWindow(parent), has_unsaved_changes(false), repository(repository)
{
    QWidget* mainWidget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(mainWidget);

    QVBoxLayout* left_side = new QVBoxLayout();

    search_widget = new SearchWidget(this);
    left_side->addWidget(search_widget);

    connect(search_widget, &SearchWidget::searchButtonClicked, this, &MainWindow::search);

    sensors_list = new SensorsList(this);
    left_side->addWidget(sensors_list);
    std::vector<Sensor*> list = repository->getAll();
    sensors_list->show(&list);

    layout->addLayout(left_side);

    sensor_graph_widget = new SensorGraphWidget(this);
    layout->addWidget(sensor_graph_widget);

    connect(sensors_list, &SensorsList::sensorSelected, sensor_graph_widget, &SensorGraphWidget::setSensor);

    mainWidget->setLayout(layout);
    mainWidget->setMinimumSize(800, 600);
    mainWidget->setBackgroundRole(QPalette::Light);
    
    setCentralWidget(mainWidget);

    setWindowTitle("EveryWeather");
    //setMinimumSize(800, 600);
    setBackgroundRole(QPalette::Light);

    create_sensor = new QAction(
        //QIcon(QPixmap((":/assets/icons/new_sensor.svg"))),
        "Add New Sensor"
    );
    create_sensor->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));
    create_sensor->setEnabled(true);

    //Sets menu
    QMenu* sensor_menu = menuBar()->addMenu("&Sensor");
    sensor_menu->addAction(create_sensor);

    connect(create_sensor, &QAction::triggered, this, &MainWindow::createSensor);
}

Repository* MainWindow::getRepository() {
    return repository;
}

MainWindow& MainWindow::reloadData() {  //refreshes the sensors list da rivedere
    std::vector<Sensor*> list = repository->getAll();
    sensors_list->show(&list);
    return *this;
}

void MainWindow::createSensor() {
    SensorEditorDialog dialog(this, repository, nullptr);
    if (dialog.exec() == QDialog::Accepted) {
        
        has_unsaved_changes = true;
        
    }
}

void MainWindow::editSensor(const Sensor* sensor) {
    SensorEditorDialog dialog(this, repository, sensor);
    if (dialog.exec() == QDialog::Accepted) {
        
        has_unsaved_changes = true;
    }
}

void MainWindow::search(const QString& city) {
    QString case_ins_city = city.toLower();
    case_ins_city[0] = case_ins_city[0].toUpper();
    std::vector<Sensor*> list = repository->search(case_ins_city.toStdString());
    sensors_list->show(&list);
}

void MainWindow::close() {
    if (has_unsaved_changes) {
        QMessageBox::StandardButton confirmation;
        confirmation = QMessageBox::question(
            this,
            "Quit?",
            "There are unsaved changes.\nDo you really want to quit?",
            QMessageBox::Yes | QMessageBox::No
            );
        if (confirmation == QMessageBox::Yes) {
            QApplication::quit();
        }
    } else {
        QApplication::quit();
    }
}
