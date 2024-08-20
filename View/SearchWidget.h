#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class SearchWidget : public QWidget {
    Q_OBJECT

    private:
        QLineEdit* searchLineEdit;
        QPushButton* searchButton;

    public:
        SearchWidget(QWidget *parent = nullptr);

    signals:
        void searchButtonClicked(const QString& research);
};

#endif // SEARCHWIDGET_H
