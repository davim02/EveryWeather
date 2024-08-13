#include "HumidityEditor.h"
#include "../../model/Humidity.h"
#include <QFormLayout>

HumidityEditor::HumidityEditor(QWidget* parent): SensorEditor(parent) {
    // FOR FUTURE IMPLEMENTATION
}

HumidityEditor::~HumidityEditor() {}

Sensor* HumidityEditor::create(const unsigned int id, const QString& city, const QString& country) const {
    return new Humidity(id, city.toStdString(), country.toStdString());
}

void HumidityEditor::setValues(const Humidity& humidity) {
    // FOR FUTURE IMPLEMENTATION
}
