#ifndef VIEW_SENSORS_LIST_H
#define VIEW_SENSORS_LIST_H

#include "../View/SensorRenderer/SensorWidget.h"
#include "../model/Repository/Repository.h"
#include <QVBoxLayout>


class SensorsList: public QWidget {
    Q_OBJECT
    private:
        Repository* repository;
        QVBoxLayout* vlayout;

    public:
        explicit SensorsList(Repository* repository, QWidget *parent = nullptr);
    
    signals:
        void sensorSelected(const Sensor* sensor);

    public slots:
        void show();
};


#endif
