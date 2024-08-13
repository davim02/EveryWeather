#ifndef RAINFALLEDITOR_H
#define RAINFALLEDITOR_H

#include "SensorEditor.h"
#include <QRadioButton>

class RainfallEditor : public SensorEditor {

    private:
        QRadioButton *mm;
        QRadioButton *inches;
    
    public:
        RainfallEditor(QWidget *parent = nullptr);
        virtual ~RainfallEditor();
        Sensor* create(
            const unsigned int id,
            const QString& city,
            const QString& country
        ) const override;

        void setValues(const Rainfall& rainfall);
};

#endif // RAINFALLEDITOR_H
