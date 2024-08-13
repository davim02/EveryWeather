#ifndef TYPESELECTOR_H
#define TYPESELECTOR_H

#include <../../model/SensorVisitorConstInterface.h>
#include <QComboBox>

class TypeSelector : public SensorVisitorConstInterface {

    private:
        QComboBox* combo_box;
  
    public:
        TypeSelector(QComboBox* combo_box);
        virtual void visit(const Humidity& humidity);
        virtual void visit(const Rainfall& rainfall);
        virtual void visit(const Temperature& temperature);
        virtual void visit(const UV& uv);
        QComboBox* getComboBox();
        TypeSelector& setComboBox(QComboBox* combo_box);

};

#endif // TYPESELECTOR_H
