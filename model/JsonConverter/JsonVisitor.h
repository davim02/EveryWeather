#ifndef JSON_VISITOR_H
#define JSON_VISITOR_H

#include "../Humidity.h"
#include "../Temperature.h"
#include "../Rainfall.h"
#include "../UV.h"
#include "../SensorVisitorConstInterface.h"
#include <QJsonObject>

class JsonVisitor: public SensorVisitorConstInterface {
    
    private:
        QJsonObject json_obj;
    
    public:
        QJsonObject getJsonObj() const;
        void visit(const Humidity& humidity);
        void visit(const Temperature& temperature);
        void visit(const Rainfall& rainfall);
        void visit(const UV& uv);
        
};

#endif