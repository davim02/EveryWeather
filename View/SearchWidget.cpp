#include "SearchWidget.h"
#include <QHBoxLayout>


SearchWidget::SearchWidget(QWidget *parent)
    : QWidget(parent)
{
    
    searchLineEdit = new QLineEdit(this);
    searchLineEdit->setPlaceholderText("Search by city or ID...");

    /*if (QApplication::styleHints()->colorScheme() == Qt::ColorScheme::Dark) {
        searchLineEdit->setStyleSheet("QLineEdit { background-color: #31363b; color: #ffffff; border: 1px solid #63ace5; border-radius: 5px; padding: 5px; }");
    } else {
        searchLineEdit->setStyleSheet("QLineEdit { background-color: #ffffff; color: #000000; border: 1px solid #63ace5; border-radius: 5px; padding: 5px; }");
    }*/
    
    searchButton = new QPushButton(" Search", this);
    searchButton->setCursor(QCursor(Qt::PointingHandCursor));

    // Create the layout
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(searchLineEdit);
    layout->addWidget(searchButton);

    // Set the layout
    setLayout(layout);
    setFixedWidth(300);

    // Connect the push of enter key during line edit with the push of search button
    connect(searchLineEdit, &QLineEdit::returnPressed, searchButton, &QPushButton::click);

    // Connect the button signal to the searchButtonClicked signal
    connect(searchButton, &QPushButton::clicked, this, [this](){
        emit searchButtonClicked(searchLineEdit->text());
    });
}
