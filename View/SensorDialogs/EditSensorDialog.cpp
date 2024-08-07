#include "EditSensorDialog.h"
#include "../../model/Temperature.h"
#include "../../model/Humidity.h"
#include "../../model/Rainfall.h"
#include "../../model/UV.h"

EditSensorDialog::EditSensorDialog(QWidget *parent, const Sensor* sensor) : QDialog(parent), sensor(sensor)
{
    if (sensor) {
        setWindowTitle("Edit Sensor");
    } else {
        setWindowTitle("New Sensor");
    }
    
    setFixedSize(300, 600);
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel *idLabel = new QLabel("ID", this);
    id = new QSpinBox(this);
    id->setMinimum(1);
    id->setMaximum(1000000);
    layout->addWidget(idLabel);
    layout->addWidget(id);
    
    QLabel *cityLabel = new QLabel("City", this);
    city = new QLineEdit(this);
    layout->addWidget(cityLabel);
    layout->addWidget(city);
    
    QLabel *countryLabel = new QLabel("Country", this);
    country = new QLineEdit(this);
    layout->addWidget(countryLabel);
    layout->addWidget(country);

    QLabel *typeLabel = new QLabel("Type", this);
    type = new QComboBox(this);
    type->addItem("Temperature");
    type->addItem("Humidity");
    type->addItem("Rainfall");
    type->addItem("UV");
    layout->addWidget(typeLabel);
    layout->addWidget(type);

    if (sensor) {
        city->setText(QString::fromStdString(sensor->getCity()));
        country->setText(QString::fromStdString(sensor->getCountry()));
        type->setCurrentIndex(sensor->getType());
        id->setValue(sensor->getId());
        id->setReadOnly(true);
    }
    
    QPushButton *okButton = new QPushButton("OK", this);
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    layout->addWidget(okButton);
    
    QPushButton *cancelButton = new QPushButton("Cancel", this);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    layout->addWidget(cancelButton);
    
    setLayout(layout);
}

Sensor EditSensorDialog::getSensor() const
{
    switch (type->currentIndex()) {
    case 0:
        sensor = new Temperature(city->text(), country->text());
        break;
    case 1:
        sensor = new Humidity(city->text(), country->text());
        break;
    case 2:
        sensor = new Rainfall(city->text(), country->text());
        break;
    case 3:
        sensor = new UV(city->text(), country->text());
        break;
    default:
        break;
    }
    
    return sensor;
}
