#include "UV.h"

UV::UV(
    const unsigned int id,
    const std::string city,
    const std::string country
): Sensor(id, city, country) {

}

void UV::accept(SensorVisitorInterface& visitor) {
    visitor.visit(*this);
}

void UV::accept(SensorVisitorConstInterface &visitor) const {
    visitor.visit(*this);
}
