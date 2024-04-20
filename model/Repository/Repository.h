#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>

#include "../Sensor.h"

class Repository {
    private:
        std::vector<Sensor*> sensors;

    public:
        Repository();
        virtual ~Repository();
        Repository& add(Sensor* sensor);
        Repository& remove(Sensor* sensor);
        Repository& clear();
        std::vector<Sensor*> getAll() const;
        std::vector<Sensor*> search(const std::string& query) const;
        void saveToFile(const std::string& filename) const;
};


#endif