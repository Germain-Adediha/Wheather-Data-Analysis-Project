#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <vector>
#include <string>

struct WeatherRecord {
    std::string date;
    double temperature;
    std::string condition;
};

class WeatherData {
public:
    bool loadFromFile(const std::string& filename);
    const std::vector<WeatherRecord>& getData() const;

private:
    std::vector<WeatherRecord> data;
};

#endif // WEATHERDATA_H
