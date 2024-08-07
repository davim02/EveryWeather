#include "../../model/Sensor.h"
#include <QDialog>
#include <QLineEdit>
#include <QComboBox>

class EditSensorDialog : public QDialog
{
    Q_OBJECT
    public:
        EditSensorDialog(QWidget *parent = nullptr, const Sensor *sensor = nullptr);
        Sensor getSensor() const;
    private:
        QSpinBox *id;
        QLineEdit *city;
        QLineEdit *country;
        QComboBox *type;

        const Sensor *sensor;
};
    
