#include "Repository.h"
#include <fstream>

Repository::Repository() {
}

Repository::~Repository() {
    clear();
}

Repository& Repository::add(Sensor* sensor) {
    repository[sensor->getId()] = sensor;
    return *this;
}

Repository& Repository::remove(const unsigned int id) {
    std::map<unsigned int, Sensor*>::const_iterator it = repository.find(id);

    if(it != repository.end()) {
        delete it->second;
        repository.erase(it);
    }
    return *this;
}

Repository& Repository::update(Sensor* sensor) { 
    return add(sensor);
/* ?
    std::map<unsigned int, Sensor*>::const_iterator it = repository.find(sensor->getId());

    if(it != repository.end()) {
        delete it->second;
        repository[sensor->getId()] = sensor;
    }
    return *this;   */
}

Repository& Repository::clear() {
    for (std::map<unsigned int, Sensor*>::const_iterator it = repository.begin(); it != repository.end(); it++) {
        
        delete it->second;
    }
    
    return *this;
}

Sensor* Repository::get(const unsigned int id) const {
    std::map<unsigned int, Sensor*>::const_iterator it = repository.find(id);

    if(it != repository.end()) {
        return it->second;
    }
    return nullptr;
}

std::vector<Sensor*> Repository::getAll() const {
    std::vector<Sensor*> sensors;

    for (std::map<unsigned int, Sensor*>::const_iterator it = repository.begin(); it != repository.end(); it++) {
        sensors.push_back(it->second);
    }

    return sensors;
}

std::vector<Sensor*> Repository::search(const std::string& city) const {
    std::vector<Sensor*> result;
    for (std::map<unsigned int, Sensor*>::const_iterator it = repository.begin(); it != repository.end(); it++) {
        if ((it->second)->getCity().find(city) != std::string::npos) {
            result.push_back(it->second);
        }
    }
    return result;
}

void Repository::saveToFile(const std::string& filename) const {
    std::ofstream file(filename.c_str());
    for (std::map<unsigned int, Sensor*>::const_iterator it = repository.begin(); it != repository.end(); it++) {
        file << (it->second)->getCity() << " " << (it->second)->getCountry() << std::endl;
    }
    file.close();
}