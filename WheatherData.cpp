#include "WeatherData.h"
#include <fstream>
#include <sstream>

bool WeatherData::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        WeatherRecord record;
        std::getline(ss, record.date, ',');
        ss >> record.temperature;
        ss.ignore(1, ',');
        std::getline(ss, record.condition);

        data.push_back(record);
    }

    file.close();
    return true;
}

const std::vector<WeatherRecord>& WeatherData::getData() const {
    return data;
}
