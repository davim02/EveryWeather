
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <functional>

#include "SensorWidgetVisitor.h"
#include "SensorWidget.h"

SensorWidget::SensorWidget(const Sensor& sensor, QWidget* parent): QPushButton(parent), sensor(sensor) {
    setMinimumSize(265, 105);
    
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    SensorWidgetVisitor visitor;
    sensor.accept(visitor);
    layout->addWidget(visitor.getWidget());

    QVBoxLayout* location_layout = new QVBoxLayout();
    location_layout->setAlignment(Qt::AlignVCenter);
    city_label = new QLabel("City: " + QString::fromStdString(sensor.getCity()));
    country_label = new QLabel("Country: " + QString::fromStdString(sensor.getCountry()));
    location_layout->addWidget(city_label);
    location_layout->addWidget(country_label);

    layout->addLayout(location_layout);
    layout->addStretch();
    
    QVBoxLayout* buttons_layout = new QVBoxLayout();
    buttons_layout->setAlignment(Qt::AlignRight);

    static const QIcon edit_icon(QPixmap(":assets/icons/edit.png"));
    edit_button = new QPushButton(edit_icon, "");
    edit_button->setIconSize(QSize(27, 27));
    edit_button->setCursor(QCursor(Qt::PointingHandCursor));
    edit_button->setToolTip("Edit this sensor");
    edit_button->setVisible(false);

    static const QIcon delete_icon(QPixmap(":assets/icons/bin.png"));
    delete_button = new QPushButton(delete_icon, "");
    delete_button->setIconSize(QSize(27, 27));
    delete_button->setCursor(QCursor(Qt::PointingHandCursor));
    delete_button->setToolTip("Delete this sensor");
    delete_button->setVisible(false);
    
    buttons_layout->addWidget(edit_button);
    buttons_layout->addWidget(delete_button);

    layout->addLayout(buttons_layout);

    connect(edit_button, &QPushButton::clicked, std::bind(&SensorWidget::edit, this, &sensor));
    connect(delete_button, &QPushButton::clicked, std::bind(&SensorWidget::remove, this, sensor.getId()));
}

void SensorWidget::enterEvent(QEvent* event) {
    edit_button->setVisible(true);
    delete_button->setVisible(true);
    qDebug() << "Enter event";
}


void SensorWidget::leaveEvent(QEvent* event) {
    edit_button->setVisible(true);
    delete_button->setVisible(true);
    qDebug() << "Leave event";
}
