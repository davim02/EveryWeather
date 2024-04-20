#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include <QMainWindow>

#include "../model/Repository/Repository.h"
#include "SensorsList.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
    private:
        Repository* repository;
        SensorsList* sensors_list;
    public:
        explicit MainWindow(Repository* repository, QWidget *parent = 0);
        Repository* getRepository();
        MainWindow& reloadData();

};

#endif