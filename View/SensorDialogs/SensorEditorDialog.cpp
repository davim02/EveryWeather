#include "SensorEditorDialog.h"
#include "TypeSetter.h"
#include "../../model/Temperature.h"
#include "../../model/Humidity.h"
#include "../../model/Rainfall.h"
#include "../../model/UV.h"


#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>

SensorEditorDialog::SensorEditorDialog(
        MainWindow *mainWindow,
        Repository *repository,
        const Sensor* sensor
    ) 
        : mainWindow(mainWindow), sensor(sensor)
{
    if (sensor) {
        setWindowTitle("Edit Sensor");
    } else {
        setWindowTitle("New Sensor");
    }
    
    setFixedSize(300, 600);
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel *title;
    if (sensor) {
        title = new QLabel("Change sensor's informations");
    } else {
        title = new QLabel("Create new sensor");
    }
    layout->addWidget(title);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->setLabelAlignment(Qt::AlignLeft | Qt::AlignTop);
    //formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
    layout->addLayout(formLayout);

    id = new QSpinBox();
    id->setMinimum(1);
    id->setMaximum(1000000);
    if (sensor) {
        id->setValue(sensor->getId());
        id->setReadOnly(true);
    }
    formLayout->addRow("ID", id);
    
    city = new QLineEdit();
    if (sensor) {
        city->setText(QString::fromStdString(sensor->getCity()));
    }
    formLayout->addRow("City", city);
    
    country = new QLineEdit();
    if (sensor) {
        country->setText(QString::fromStdString(sensor->getCountry()));
    }
    formLayout->addRow("Country", country);

    type = new QComboBox();
    type->addItem("Temperature");
    type->addItem("Humidity");
    type->addItem("Rainfall");
    type->addItem("UV");
    if (sensor) {
        TypeSetter type_setter(type);
        sensor->accept(type_setter);
    }
    formLayout->addRow("Type", type);

    QPushButton *okButton = new QPushButton("OK");
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    layout->addWidget(okButton);
    
    QPushButton *cancelButton = new QPushButton("Cancel");
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    layout->addWidget(cancelButton);
    
}

Sensor* SensorEditorDialog::getSensor() const
{
    switch (type->currentIndex()) {
    case 0:
        sensor = new Temperature(id->text(), city->text(), country->text());
        break;
    case 1:
        sensor = new Humidity(id->text(), city->text(), country->text());
        break;
    case 2:
        sensor = new Rainfall(id->text(), city->text(), country->text());
        break;
    case 3:
        sensor = new UV(id->text(), city->text(), country->text());
        break;
    default:
        break;
    }
    
    return &sensor;
}
