#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "../model/Repository/Repository.h"

class MainWidget : public QWidget
{
    Q_OBJECT
private:
    Repository *repository;

public:
    explicit MainWidget(Repository *repository, QWidget *parent = 0);

/*public slots:
        void onSensorSelected(const Sensor* sensor);
        void onSensorDeselected(const Sensor* sensor);
        void onSensorAdded(const Sensor* sensor);
        void onSensorRemoved(const Sensor* sensor);
        void onSensorUpdated(const Sensor* sensor);*/
};

#endif // MAINWIDGET_H
