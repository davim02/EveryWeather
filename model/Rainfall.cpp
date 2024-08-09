#include "Rainfall.h"

Rainfall::Rainfall(
    const unsigned int id,
    const std::string city,
    const std::string country,
    bool is_inches
): Sensor(id, city, country), is_inches(is_inches) {
    
}

bool Rainfall::isInches() const {
    return is_inches;
}

void Rainfall::accept(SensorVisitorInterface& visitor) {
    visitor.visit(*this);
}

void Rainfall::accept(SensorVisitorConstInterface& visitor) const {
    visitor.visit(*this);
}
