#include "MainWindow.h"
#include "SensorDialogs/SensorEditorDialog.h"
#include "../model/JsonConverter/Reader.h"
#include "../model/JsonConverter/Json.h"
#include "../model/JsonFileIO/JsonFile.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QStyleHints>
#include <QMessageBox>
#include <QRegularExpression>
#include <QDir>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), has_unsaved_changes(false), repository(nullptr) {

    QAction* create = new QAction("New");
    create->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    connect(create, &QAction::triggered, this, &MainWindow::newDataset);

    QAction* open = new QAction("Open");
    open->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    connect(open, &QAction::triggered, this, &MainWindow::openDataset);

    QAction* save = new QAction("Save");
    save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    connect(save, &QAction::triggered, this, &MainWindow::saveDataset);

    QAction* save_as = new QAction("Save As");
    save_as->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    connect(save_as, &QAction::triggered, this, &MainWindow::saveAsDataset);

    QAction* close = new QAction("Close");
    close->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
    connect(close, &QAction::triggered, this, &MainWindow::close);

    create_sensor = new QAction("Add New Sensor");
    create_sensor->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));
    create_sensor->setEnabled(false);
    connect(create_sensor, &QAction::triggered, this, &MainWindow::createSensor);

    /*if (QApplication::styleHints()->colorScheme() == Qt::ColorScheme::Dark) {
        create->setIcon(QIcon(QPixmap(":/assets/icons/new-file_white.png")));
        open->setIcon(QIcon(QPixmap(":/assets/icons/open-file_white.png")));
        save->setIcon(QIcon(QPixmap(":/assets/icons/save_white.png")));
        save_as->setIcon(QIcon(QPixmap(":/assets/icons/save-as_white.png")));
        close->setIcon(QIcon(QPixmap(":/assets/icons/close_white.png")));
        create_sensor->setIcon(QIcon(QPixmap(":/assets/icons/new-sensor_white.png")));
    } else {*/
        create->setIcon(QIcon(QPixmap(":/assets/icons/new-file.png")));
        open->setIcon(QIcon(QPixmap(":/assets/icons/open-file.png")));
        save->setIcon(QIcon(QPixmap(":/assets/icons/save.png")));
        save_as->setIcon(QIcon(QPixmap(":/assets/icons/save-as.png")));
        close->setIcon(QIcon(QPixmap(":/assets/icons/close.png")));
        create_sensor->setIcon(QIcon(QPixmap(":/assets/icons/new-sensor.png")));
    //}
    
    //Sets menu
    QMenu* file = menuBar()->addMenu("&File");
    file->addAction(create);
    file->addAction(open);
    file->addAction(save);
    file->addAction(save_as);
    file->addSeparator();
    file->addAction(close);
    QMenu* sensor_menu = menuBar()->addMenu("&Sensor");
    sensor_menu->addAction(create_sensor);

    //Sets main widget
    QWidget* mainWidget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(mainWidget);

    QVBoxLayout* left_side = new QVBoxLayout();

    search_widget = new SearchWidget(this);
    left_side->addWidget(search_widget);
    left_side->setAlignment(search_widget, Qt::AlignTop);

    connect(search_widget, &SearchWidget::searchButtonClicked, this, &MainWindow::search);

    sensors_list = new SensorsList(this);
    left_side->addWidget(sensors_list);

    layout->addLayout(left_side);

    sensor_graph_widget = new SensorGraphWidget(this);
    layout->addWidget(sensor_graph_widget);

    connect(sensors_list, &SensorsList::sensorSelected, sensor_graph_widget, &SensorGraphWidget::setSensor);
    connect(sensors_list, &SensorsList::editSensor, this, &MainWindow::editSensor);
    connect(sensors_list, &SensorsList::removeSensor, this, &MainWindow::removeSensor);

    mainWidget->setLayout(layout);
    mainWidget->setMinimumSize(800, 600);
    
    setCentralWidget(mainWidget);

    setWindowTitle("EveryWeather");
}

JsonRepository* MainWindow::getRepository() {
    return repository;
}

MainWindow& MainWindow::reloadRepo() { 
    std::vector<Sensor*> list = repository->getAll();
    sensors_list->show(&list);
    return *this;
}

void MainWindow::newDataset() {
    if (has_unsaved_changes) {
            QMessageBox::StandardButton confirmation;
            confirmation = QMessageBox::question(
                this,
                "Save changes?",
                "Current dataset has unsaved changes.\nDo you want to save them?",
                QMessageBox::Yes | QMessageBox::No
            );
            if (confirmation == QMessageBox::Yes) {
                saveDataset();
            }
    }
    QString filepath = QFileDialog::getSaveFileName(
        this, 
        "Save new dataset", 
        QDir::homePath(), 
        "JSON files (*.json)"
    );
    if (filepath.isEmpty()) {
        return; // User cancelled
    }
    if (repository != nullptr) {
        delete repository;
    }
    Reader reader;
    Json json_converter(reader);
    JsonFile data_mapper(filepath.toStdString(), json_converter);
    repository = new JsonRepository(data_mapper);
    create_sensor->setEnabled(true);
}

void MainWindow::openDataset() {
    if (has_unsaved_changes) {
        QMessageBox::StandardButton confirmation;
        confirmation = QMessageBox::question(
            this,
            "Save changes?",
            "Current dataset has unsaved changes.\nDo you want to save them?",
            QMessageBox::Yes | QMessageBox::No
        );
        if (confirmation == QMessageBox::Yes) {
            saveDataset();
        }
    }
    QString filepath = QFileDialog::getOpenFileName(
        this, 
        "Open dataset", 
        QDir::homePath(), 
        "JSON files (*.json)"
    );
    if (filepath.isEmpty()) {
        return; // User cancelled
    }
    if (repository != nullptr) {
        delete repository;
    }
    Reader reader;
    Json json_converter(reader);
    JsonFile data_mapper(filepath.toStdString(), json_converter);
    repository = new JsonRepository(data_mapper);
    create_sensor->setEnabled(true);
    reloadRepo();
}

void MainWindow::saveDataset() {
    if (repository == nullptr) {
        QMessageBox::warning(this, "Error", "No dataset is currently open");
        return;
    }
    repository->store();
    has_unsaved_changes = false;
}

void MainWindow::saveAsDataset() {
    if (repository == nullptr) {
        QMessageBox::warning(this, "Error", "No dataset is currently open");
        return;
    }
    QString filepath = QFileDialog::getSaveFileName(
        this, 
        "Save dataset as", 
        QDir::homePath(), 
        "JSON files (*.json)"
    );
    if (filepath.isEmpty()) {
        return; // User cancelled
    }
    repository->setFilepath(filepath.toStdString()).store();
    has_unsaved_changes = false;
}

void MainWindow::createSensor() {
    SensorEditorDialog dialog(this, nullptr);
    if (dialog.exec() == QDialog::Accepted) {
        has_unsaved_changes = true;
    }
}

void MainWindow::removeSensor(const unsigned int sensor_id) {
    
    if (sensor_graph_widget->isSensorSet()) {
        if (sensor_id == sensor_graph_widget->getSensor()->getId()) {
            sensor_graph_widget->reset();
        }
    }

    repository->remove(sensor_id);
    reloadData();
    has_unsaved_changes = true;
}

void MainWindow::editSensor(const Sensor* sensor) {
    SensorEditorDialog dialog(this, sensor);
    if (dialog.exec() == QDialog::Accepted) {
        if (sensor_graph_widget->isSensorSet()) {
            qDebug() << "sensor is set";
            qDebug() << sensor->getId();
            qDebug() << sensor_graph_widget->getSensor()->getId();
            if (sensor->getId() == sensor_graph_widget->getSensor()->getId()) {
                sensor_graph_widget->reset();
                qDebug() << "reset done";
            }
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
        QStringList temp = saved_research.toLower().split(" ");
        QString case_ins_city = "";
        for (int i = 0; i < temp.size(); i++) {
            auto word = temp[i];
            word[0] = word[0].toUpper();
            case_ins_city += word;
            if (i < temp.size() - 1) {
                case_ins_city += " ";
            }
        }
        
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
        saved_research = "";
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
    QApplication::quit();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (has_unsaved_changes) {
        QMessageBox::StandardButton confirmation;
        confirmation = QMessageBox::question(
            this,
            "Quit?",
            "There are unsaved changes.\nDo you really want to quit?",
            QMessageBox::Yes | QMessageBox::No
            );
        if (confirmation == QMessageBox::Yes) {
            event->accept();
        } else {
            event->ignore();
        }
    } else {
        event->accept();
    }
}
