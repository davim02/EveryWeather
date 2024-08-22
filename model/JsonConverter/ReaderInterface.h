#ifndef READER_INTERFACE_H
#define READER_INTERFACE_H

#include <QJsonObject>
#include "../Sensor.h"

class ReaderInterface {
    public:
        virtual ~ReaderInterface() = default;
        virtual Sensor* read(const QJsonObject& json_obj) = 0;
};

#endif
