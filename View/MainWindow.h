#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include "../model/Repository/Repository.h"
#include "SensorsList.h"
#include "GraphRenderer/SensorGraphWidget.h"
#include <QMainWindow>
#include <QToolBar>
#include <QAction>


class MainWindow : public QMainWindow {
    Q_OBJECT
    private:
        bool has_unsaved_changes;
        SensorsList* sensors_list;
        SensorGraph* sensor_graph;
        QAction* create_sensor;
        QToolBar* toolbar;

        
    public:
        explicit MainWindow(Repository *repository, QWidget *parent = 0);
        Repository* getRepository();
        MainWindow& reloadData();

    public slots:
    void createSensor();
    void editSensor(const Sensor* sensor);
    void close();
        /*void onSensorSelected(const Sensor* sensor);
        void onSensorDeselected(const Sensor* sensor);
        void onSensorAdded(const Sensor* sensor);
        void onSensorRemoved(const Sensor* sensor);
        void onSensorUpdated(const Sensor* sensor);*/
};

#endif
