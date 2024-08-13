#ifndef TEMPERATUREEDITOR_H
#define TEMPERATUREEDITOR_H

#include "SensorEditor.h"
#include <QRadioButton>

class TemperatureEditor : public SensorEditor {
    private:
        QRadioButton *celsius;
        QRadioButton *fahrenheit;
    
    public:
        TemperatureEditor(QWidget *parent = nullptr);
        virtual ~TemperatureEditor();
        Sensor* create(
            const unsigned int id,
            const QString& city,
            const QString& country
        ) const override;

        void setValues(const Temperature& temperature);
};

#endif // TEMPERATUREEDITOR_H
