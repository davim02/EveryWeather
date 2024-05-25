#include "SensorsList.h"

#include <QVBoxLayout>
#include <QScrollArea>

SensorsList::SensorsList(Repository* repository, QWidget *parent)
    : QWidget(parent), repository(repository)
{

    vlayout = new QVBoxLayout();
    vlayout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    
    QWidget* container = new QWidget();
    container->setLayout(vlayout);

    QScrollArea* scroll_area = new QScrollArea();
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);
}

void SensorsList::show() {
    
    SensorWidgetVisitor visitor;
    
    for (auto sensor : repository->getAll()) {
        sensor->accept(visitor);
        vlayout->addWidget(visitor.getWidget());  
    }
}

