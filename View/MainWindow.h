#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include <QMainWindow>
#include "MainWidget.h"
#include "../model/Repository/Repository.h"


class MainWindow : public QMainWindow {
    Q_OBJECT
    private:
        
        MainWidget* mainWidget;
        
    public:
        explicit MainWindow(Repository *repository, QWidget *parent = 0);
        Repository* getRepository();
        MainWindow& reloadData();

    /*public slots:
        void onSensorSelected(const Sensor* sensor);
        void onSensorDeselected(const Sensor* sensor);
        void onSensorAdded(const Sensor* sensor);
        void onSensorRemoved(const Sensor* sensor);
        void onSensorUpdated(const Sensor* sensor);*/
};

#endif
