#include "SearchWidget.h"
#include <QHBoxLayout>

SearchWidget::SearchWidget(QWidget *parent)
    : QWidget(parent)
{
    // Create the search line edit
    searchLineEdit = new QLineEdit(this);
    searchLineEdit->setPlaceholderText("Search by city or ID...");

    // Create the search button
    searchButton = new QPushButton("Search", this);

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
