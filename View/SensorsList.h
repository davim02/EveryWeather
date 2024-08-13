#ifndef VIEW_SENSORS_LIST_H
#define VIEW_SENSORS_LIST_H

#include "../View/SensorRenderer/SensorWidget.h"
#include "../model/Sensor.h"
#include <QVBoxLayout>


class SensorsList: public QWidget {
    Q_OBJECT
    private:
        std::vector<Sensor*>* sensors_list;
        QVBoxLayout* vlayout;

    public:
        explicit SensorsList(QWidget *parent = nullptr);
    
    signals:
        void sensorSelected(const Sensor* sensor);

    public slots:
        void show(std::vector<Sensor*>* results);
        void show();
        void clear();
};


#endif
