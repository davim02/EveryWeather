#include "Sensor.h"

Sensor::Sensor(const std::string city, const std::string country) : city(city), country(country) {
}

Sensor::~Sensor() {
}

const std::string& Sensor::getCity() const {
    return city;
}

const std::string& Sensor::getCountry() const {
    return country;
}

void Sensor::setCity(const std::string city) {
    this->city = city;
}

void Sensor::setCountry(const std::string country) {
    this->country = country;
}

