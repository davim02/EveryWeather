#include "TemperatureEditor.h"
#include "../../model/Temperature.h"
#include <QFormLayout>
#include <QHBoxLayout>

TemperatureEditor::TemperatureEditor(QWidget* parent) : SensorEditor(parent) {

    QFormLayout *layout = new QFormLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QHBoxLayout *button_group = new QHBoxLayout();
    button_group->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    celsius = new QRadioButton("Celsius", this);
    fahrenheit = new QRadioButton("Fahrenheit", this);
    button_group->addWidget(celsius);
    button_group->addWidget(fahrenheit);

    layout->addRow("Measurement Unit", button_group);
}

TemperatureEditor::~TemperatureEditor() {}

Sensor* TemperatureEditor::create(const unsigned int id, const QString& city, const QString& country) const {
    return new Temperature(id, city.toStdString(), country.toStdString(), fahrenheit->isChecked());
}

void TemperatureEditor::setValues(const Temperature& temperature) {
    if (temperature.isFahrenheit()) {
        fahrenheit->setChecked(true);
    } else {
        celsius->setChecked(true);
    }
}
