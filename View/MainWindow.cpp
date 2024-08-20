#include "MainWindow.h"
#include "SensorDialogs/SensorEditorDialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QMessageBox>
#include <QRegularExpression>


MainWindow::MainWindow(Repository* repository, QWidget *parent): QMainWindow(parent), has_unsaved_changes(false), repository(repository)
{
    QWidget* mainWidget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(mainWidget);

    QVBoxLayout* left_side = new QVBoxLayout();

    search_widget = new SearchWidget(this);
    left_side->addWidget(search_widget);
    left_side->setAlignment(search_widget, Qt::AlignTop);
    //left_side->addStretch();

    connect(search_widget, &SearchWidget::searchButtonClicked, this, &MainWindow::search);

    sensors_list = new SensorsList(this);
    left_side->addWidget(sensors_list);
    std::vector<Sensor*> list = repository->getAll();
    sensors_list->show(&list);

    layout->addLayout(left_side);

    sensor_graph_widget = new SensorGraphWidget(this);
    layout->addWidget(sensor_graph_widget);

    connect(sensors_list, &SensorsList::sensorSelected, sensor_graph_widget, &SensorGraphWidget::setSensor);
    connect(sensors_list, &SensorsList::editSensor, this, &MainWindow::editSensor);
    connect(sensors_list, &SensorsList::removeSensor, this, &MainWindow::removeSensor);

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

MainWindow& MainWindow::reloadRepo() { 
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

void MainWindow::removeSensor(const unsigned int sensor_id) {
    repository->remove(sensor_id);
    reloadData();
    if (sensor_id == sensor_graph_widget->getSensor()->getId()) {
        sensor_graph_widget->reset();
    }
    has_unsaved_changes = true;
}

void MainWindow::editSensor(const Sensor* sensor) {
    SensorEditorDialog dialog(this, repository, sensor);
    if (dialog.exec() == QDialog::Accepted) {
        if (sensor->getId() == sensor_graph_widget->getSensor()->getId()) {
            sensor_graph_widget->reset();
        }
        has_unsaved_changes = true;
    }
}

void MainWindow::showResults() {
    std::vector<Sensor*> list;
    static QRegularExpression re(QRegularExpression::anchoredPattern("\\d*"));  // a digit (\d), zero or more times (*)

    if (re.match(saved_research).hasMatch()) {
        unsigned int id = saved_research.toUInt();
        list = repository->search(id);
    } else {
        QString case_ins_city = saved_research.toLower();
        case_ins_city[0] = case_ins_city[0].toUpper();
        list = repository->search(case_ins_city.toStdString());
    }

    if (list.empty()) {
        sensors_list->showNoResults();
    } else {
        sensors_list->show(&list);
    }
}

void MainWindow::search(const QString& research) {
    if (!research.isEmpty()) {
        saved_research = research;
        showResults();
    } else {
        reloadRepo();
    }  
}

MainWindow& MainWindow::reloadData() {
    if (!saved_research.isEmpty()) {
        showResults();
    } else {
        reloadRepo();
    }
    
    return *this;
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
