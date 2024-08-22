#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include "../model/Repository/JsonRepository.h"
#include "SensorsList.h"
#include "SearchWidget.h"
#include "GraphRenderer/SensorGraphWidget.h"
#include <QMainWindow>
#include <QToolBar>
#include <QAction>


class MainWindow : public QMainWindow {
    Q_OBJECT
    private:
        bool has_unsaved_changes;
        JsonRepository* repository;
        SensorsList* sensors_list;
        SearchWidget* search_widget;
        SensorGraphWidget* sensor_graph_widget;
        QString saved_research;
        QAction* create_sensor;
        QToolBar* toolbar;

    protected:
        void closeEvent(QCloseEvent *event) override;
        
    public:
        MainWindow(QWidget *parent = 0);
        JsonRepository* getRepository();
        MainWindow& reloadRepo();
        MainWindow& reloadData();
        void showResults();

    public slots:
        void newDataset();
        void openDataset();
        void saveDataset();
        void saveAsDataset();
        void createSensor();
        void editSensor(const Sensor* sensor);
        void removeSensor(const unsigned int sensor_id);
        void search(const QString& research);
        void close();
};

#endif
