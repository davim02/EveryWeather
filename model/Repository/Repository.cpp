#include "Repository.h"
#include <fstream>

Repository::Repository() {
}

Repository::~Repository() {
    clear();
}

Repository& Repository::add(Sensor* sensor) {
    sensors.push_back(sensor);
    return *this;
}

Repository& Repository::remove(Sensor* sensor) {
    for (std::vector<Sensor*>::iterator it = sensors.begin(); it != sensors.end(); ++it) {
        if (*it == sensor) {
            sensors.erase(it);
            break;
        }
    }
    return *this;
}

Repository& Repository::clear() {
    for (std::vector<Sensor*>::iterator it = sensors.begin(); it != sensors.end(); ++it) {
        delete *it;
    }
    sensors.clear();
    return *this;
}

std::vector<Sensor*> Repository::getAll() const {
    return sensors;
}

std::vector<Sensor*> Repository::search(const std::string& query) const {
    std::vector<Sensor*> result;
    for (std::vector<Sensor*>::const_iterator it = sensors.begin(); it != sensors.end(); ++it) {
        if ((*it)->getCity().find(query) != std::string::npos || (*it)->getCountry().find(query) != std::string::npos) {
            result.push_back(*it);
        }
    }
    return result;
}

void Repository::saveToFile(const std::string& filename) const {
    std::ofstream file(filename.c_str());
    for (std::vector<Sensor*>::const_iterator it = sensors.begin(); it != sensors.end(); ++it) {
        file << (*it)->getCity() << " " << (*it)->getCountry() << std::endl;
    }
    file.close();
}