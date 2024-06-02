#include "SensorsList.h"
#include "../View/SensorRenderer/SensorWidgetVisitor.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <iostream>

SensorsList::SensorsList(Repository* repository, QWidget *parent)
    : QWidget(parent), repository(repository)
{
    QWidget* container = new QWidget(this);
    vlayout = new QVBoxLayout(container);
    vlayout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QScrollArea* scroll_area = new QScrollArea(this);
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);

    show();
}

void SensorsList::show() {
    
    for (auto sensor : repository->getAll()) {

        vlayout->addWidget(new SensorWidget(*sensor));
    }

}

